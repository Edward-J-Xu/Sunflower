#ifndef SUNFLOWER_WALLET_H
#define SUNFLOWER_WALLET_H

#include <string>
#include <vector>
#include <google/protobuf/message.h>
#include "proto/signaturepb/signature.pb.h"

namespace sunflower {
namespace wallet {

// Custom types for a cipher text and shared secret
using CipherText = std::vector<uint8_t>;
using SharedSecret = std::vector<uint8_t>;

// Interface for signing a string of bytes and protobuf messages
class Signer {
public:
    virtual std::vector<uint8_t> Sign(const std::vector<uint8_t>& message) = 0;
    virtual void SignProtoMessage(google::protobuf::Message* message) = 0;
    virtual void SignProtoMessageRLPEncoded(google::protobuf::Message* message) = 0;
};

// Interface for verifying signatures as a string of bytes and protobuf messages
class Verifier {
public:
    virtual bool VerifySig(const std::vector<uint8_t>& message, const std::vector<uint8_t>& signature, const std::vector<uint8_t>& publicKey) = 0;
    virtual bool VerifyProtoMessage(const google::protobuf::Message& message) = 0;
    virtual bool VerifyProtoMessageRLPEncoded(const google::protobuf::Message& message) = 0;
};

// Interface for a signature wallet
class SigWallet : public Signer {
public:
    virtual std::string Address() const = 0;
    virtual std::vector<uint8_t> Public() const = 0;
};

// Extracts the field of name "Signature" and of type signaturepb::Signature from a struct
signaturepb::Signature* ExtractSignature(google::protobuf::Message* message, const std::string& signatureName);

// Interface for batch verification methods
class BatchVerifier {
public:
    virtual void BatchVerify(const std::vector<std::vector<uint8_t>>& publicKeys, const std::vector<std::vector<uint8_t>>& messages, const std::vector<std::vector<uint8_t>>& signatures) = 0;
    virtual void BatchVerifyProto(const std::vector<std::vector<uint8_t>>& publicKeys, const std::vector<google::protobuf::Message*>& messages, const std::vector<uint8_t>& signature) = 0;
};

// Interface for using multi-signature methods
class Aggregator {
public:
    virtual std::vector<uint8_t> AggregateSignatures(const std::vector<std::vector<uint8_t>>& signatures) = 0;
    virtual std::vector<uint8_t> AggregatePublicKeys(const std::vector<std::vector<uint8_t>>& publicKeys) = 0;
};


} // namespace wallet
} // namespace sunflower

#endif //SUNFLOWER_WALLET_H
