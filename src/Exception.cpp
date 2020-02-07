#include "Exception.hpp"

namespace haneul {
const char *HaneulException::what() const noexcept {
  return this->msg_.c_str();
}

uint32_t HaneulException::get_line_number() const noexcept {
  return this->line_number_;
}

} // namespace haneul