#include "middleware.h"
#include <grpcpp/support/status.h>
#include <google/protobuf/util/json_util.h>
#include <spdlog/spdlog.h>
#include <chrono>
#include <sstream>
#include <cstring>
#include <vector>

namespace sunflower {
namespace middleware {

grpc::Status AuthHandler::UnaryInboundingAuthInterceptor(
    grpc::ServerContext* context,
    const google::protobuf::Message* request,
    google::protobuf::Message* response,
    grpc::ServerCompletionQueue* cq
) {
    std::string serviceName, methodName;
    std::tie(serviceName, methodName) = splitMethodString(context->method());

    if (filterEndpoints_(serviceName, methodName)) {
        // Check and verify signature
        if (request->GetDescriptor()->FindFieldByName("Signature") != nullptr) {
            if (verifier_->VerifyProtoMessage(*request) != grpc::Status::OK) {
                return grpc::Status(grpc::StatusCode::UNAUTHENTICATED, "Invalid signature");
            }
        }
        // Call the handler and get response
        auto status = context->server->RequestUnary(&context->method(), request, response, cq, cq, (void*)this);
        if (!status.ok()) {
            return status;
        }

        // Sign response
        if (response->GetDescriptor()->FindFieldByName("Signature") && !response->GetReflection()->HasField(*response, response->GetDescriptor()->FindFieldByName("Signature"))) {
            if (verifier_->SignProtoMessage(response) != grpc::Status::OK) {
                return grpc::Status(grpc::StatusCode::INTERNAL, "Failed to sign response");
            }
        }

        return grpc::Status::OK;
    }
    return grpc::Status(grpc::StatusCode::PERMISSION_DENIED, "Endpoint not permitted");
}

grpc::Status AuthHandler::UnaryOutgoingAuthInterceptor(
    grpc::ClientContext* context,
    const google::protobuf::Message* request,
    google::protobuf::Message* response,
    grpc::CompletionQueue* cq) {

    std::string serviceName, methodName;
    std::tie(serviceName, methodName) = splitMethodString(context->method());

    if (filterEndpoints_(serviceName, methodName)) {
        // Sign the request
        if (request->GetDescriptor()->FindFieldByName("Signature") && !request->GetReflection()->HasField(*request, request->GetDescriptor()->FindFieldByName("Signature"))) {
            if (verifier_->SignProtoMessage(request) != grpc::Status::OK) {
                return grpc::Status(grpc::StatusCode::INTERNAL, "Signature signing failed");
            }
        }
        
        auto status = context->channel->PerformUnary(context, request, response, cq);
        if (!status.ok()) {
            return status;
        }

        // Verify the response
        if (response->GetDescriptor()->FindFieldByName("Signature")) {
            if (verifier_->VerifyProtoMessage(response) != grpc::Status::OK) {
                return grpc::Status(grpc::StatusCode::UNAUTHENTICATED, "Signature verification failed");
            }
        }

        return grpc::Status::OK;
    }
    return grpc::Status(grpc::StatusCode::PERMISSION_DENIED, "Endpoint not allowed");
}

grpc::Status LogHandler::UnaryInboundingLogInterceptor(
    grpc::ServerContext* context,
    const google::protobuf::Message* request,
    google::protobuf::Message* response,
    grpc::ServerCompletionQueue* cq) {

    std::string serviceName, methodName;
    std::tie(serviceName, methodName) = splitMethodString(context->method());

    if (filterEndpoints_(serviceName, methodName)) {
        spdlog::info("Inbound request to {}.{}", serviceName, methodName);

        auto start = std::chrono::high_resolution_clock::now();

        auto status = context->server->RequestUnary(&context->method(), request, response, cq, cq, (void*)this);
        if (!status.ok()) {
            spdlog::error("Request handling failed: {}", status.error_message());
            return status;
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        spdlog::info("Request handled in {} seconds", elapsed.count());
        return grpc::Status::OK;
    }
    return grpc::Status(grpc::StatusCode::PERMISSION_DENIED, "Endpoint not allowed");
}

grpc::Status LogHandler::UnaryOutgoingLogInterceptor(
    grpc::ClientContext* context,
    const google::protobuf::Message* request,
    const google::protobuf::Message* response,
    grpc::CompletionQueue* cq) {

    std::string serviceName, methodName;
    std::tie(serviceName, methodName) = splitMethodString(context->method());

    if (filterEndpoints_(serviceName, methodName)) {
        spdlog::info("Outgoing request to {}.{}", serviceName, methodName);

        auto start = std::chrono::high_resolution_clock::now();

        auto status = context->channel->PerformUnary(context, request, response, cq);
        if (!status.ok()) {
            spdlog::error("Request handling failed: {}", status.error_message());
            return status;
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        spdlog::info("Request handled in {} seconds", elapsed.count());
        return grpc::Status::OK;
    }
    return grpc::Status(grpc::StatusCode::PERMISSION_DENIED, "Endpoint not allowed");
}

std::pair<std::string, std::string> splitMethodString(const std::string& methodName) {
    std::istringstream iss(methodName);
    std::string serviceName, method;
    std::getline(iss, serviceName, '/');
    std::getline(iss, method, '/');
    return { serviceName, method };
}


} // namespace middleware
} // namespace sunflower

