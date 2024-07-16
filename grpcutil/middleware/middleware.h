#ifndef SUNFLOWER_MIDDLEWARE_H
#define SUNFLOWER_MIDDLEWARE_H

#include <string>
#include <grpcpp/grpcpp.h>
#include <google/protobuf/message.h>
#include <functional>
#include "wallet.h"

namespace sunflower {
namespace grpcutil {

// Filter function to exclude endpoints that don't need authentication
using FilterFunc = std::function<bool(const std::string& serviceName, const std::string& methodName)>;

// Handles signing requests and verifying signatures in responses
class AuthHandler {
public:
    AuthHandler(std::shared_ptr<wallet::SigWallet> sigWallet, std::shared_ptr<wallet::Verifier> verifier, FilterFunc filter)
        : sigWallet_(sigWallet), verifier_(verifier), filterEndpoints_(filter) {}
    
    grpc::Status UnaryInboundingAuthInterceptor(
        grpc::ServerContext* context,
        const google::protobuf::Message* request,
        google::protobuf::Message* response,
        grpc::ServerCompletionQueue* cq
    );

    grpc::Status UnaryOutgoingAuthInterceptor(
        grpc::ClientContext* context,
        const google::protobuf::Message* request,
        google::protobuf::Message* response,
        grpc::ServerCompletionQueue* cq
    );

private:
    std::shared_ptr<wallet::SigWallet> sigWallet_;
    std::shared_ptr<wallet::Verifier> verifier_;
    FilterFunc filterEndpoints_;
};

// Handles logging of requests and responses
class LogHandler {
public:
    LogHandler(FilterFunc filter) : filterEndpoints_(filter) {}

    grpc::Status UnaryInboundingLogInterceptor(
        grpc::ServerContext* context,
        const google::protobuf::Message* request,
        google::protobuf::Message* response,
        grpc::ServerCompletionQueue* cq
    );
    
    grpc::Status UnaryOutgoingLogInterceptor(
        grpc::ClientContext* context,
        const google::protobuf::Message* request,
        google::protobuf::Message* response,
        grpc::CompletionQueue* cq
    );

private:
    FilterFunc filterEndpoints_;
};

std::pair<std::string, std::string> splitMethodString(const std::string& methodName);

} // namespace grpcutil
} // namespace sunflower

#endif //SUNFLOWER_MIDDLEWARE_H
