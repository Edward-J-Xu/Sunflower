#ifndef SUNFLOWER_COMMON_H
#define SUNFLOWER_COMMON_H

#include <array>
#include <cstdint>
#include <vector>
#include "wallet/keypair.h"

namespace sunflower {
namespace common {

using Hash64 = std::array<uint8_t, 32>;

wallet::Address bytesToAddress(const std::vector<uint8_t>& addr);
Hash64 bytesToHash64(const std::vector<uint8_t>& addr);

}  // namespace common
}  // namespace sunflower

#endif
