#include "Util.hpp"

namespace haneul {
namespace util {

std::string char32_to_string(char32_t ch) {
  if (ch == 0)
    return "\0";

  char bytes[4];
  bytes[0] = (ch >> 24) & 0xFF;
  bytes[1] = (ch >> 16) & 0xFF;
  bytes[2] = (ch >> 8) & 0xFF;
  bytes[3] = ch & 0xFF;

  std::string result = "";
  for (std::size_t i = 0; i < 4; i++) {
    if (bytes[i] != 0) {
      result += bytes[i];
    }
  }

  return result;
}

} // namespace util
} // namespace haneul