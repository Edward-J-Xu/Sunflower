#include "common.h"

namespace sunflower {
namespace common {

wallet::Address bytesToAddress(const std::vector<uint8_t>& bytes) {
    if (bytes.size() != 32) {
        throw std::runtime_error("Invalid address bytes length: " + std::to_string(bytes.size()));
    }
    wallet::Address address = {};
    std::copy(bytes.begin(), bytes.begin() + std::min(bytes.size(), address.size()), address.begin());
    return address;
}

Hash64 bytesToHash64(const std::vector<uint8_t>& addr) {
    if (addr.size() != 32) {
        throw std::runtime_error("Invalid address bytes length: " + std::to_string(addr.size()));
    }
    Hash64 hash = {};
    std::copy(addr.begin(), addr.begin() + std::min(addr.size(), hash.size()), hash.begin());
    return hash;
}

}  // namespace common
}  // namespace sunflower
