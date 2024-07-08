#ifndef SUNFLOWER_KEYPAIR_H
#define SUNFLOWER_KEYPAIR_H

#include <array>
#include <string>
#include <vector>

namespace sunflower {
namespace wallet {

using PublicKey = std::vector<uint8_t>;
using Address = std::array<uint8_t, 32>;

class KeyPair {
public:
    KeyPair(const PublicKey& PublicKey, const std::vector<uint8_t>& privateKey);

    PublicKey getPublicKey() const;
    std::vector<uint8_t> getPrivateKey() const;
    Address getAddress() const;

    bool writeTo(const std::string& dir, const std::string& prefix) const;
    void clean();

    static bool isHexAddress(const std::string& hexAddress);
    static Address fromHexAddress(const std::string& hexAddress);
    static std::string toHexAddress(const Address& address);
    static Address bytesToAddress(const std::vector<uint8_t>& bytes);

    static PublicKey readPubKey(const std::string& pubKeyFile, std::vector<uint8_t>& rest);
    static std::vector<uint8_t> readPrivKey(const std::string& privKeyFile, std::vector<uint8_t>& rest);

private:
    PublicKey publicKey;
    std::vector<uint8_t> privateKey;
    mutable Address address;
};


}  // namespace wallet
}  // namespace sunflower

#endif //SUNFLOWER_KEYPAIR_H
