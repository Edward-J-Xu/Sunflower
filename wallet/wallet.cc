#include "wallet.h"
#include <google/protobuf/reflection.h>

namespace sunflower {
namespace wallet {

using namespace google::protobuf;

signaturepb::Signature* ExtractSignature(Message* message, const std::string& signatureName) {
    const Reflection* reflection = message->GetReflection();
    const Descriptor* descriptor = message->GetDescriptor();
    const FieldDescriptor* field = descriptor->FindFieldByName(signatureName);

    if (field == nullptr || field->cpp_type() != FieldDescriptor::CPPTYPE_MESSAGE) {
        return nullptr;
    }

    const Message& fieldMessage = reflection->GetMessage(*message, field);

    return dynamic_cast<signaturepb::Signature*>(&fieldMessage);
}

}  // namespace wallet
}  // namespace sunflower
