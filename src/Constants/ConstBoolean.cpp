#include "Constants/ConstBoolean.hpp"

namespace haneul {
Constant ConstBoolean::operator==(ConstantPtr other) const {
  switch (other->type) {
  case ConstantType::Boolean: {
    auto derived = static_cast<const ConstBoolean *>(other);
    return ConstBoolean(this->value == derived->value);
  }
  default:
    return ConstBoolean(false);
  }
}

std::string ConstBoolean::show() const { return this->value ? "참" : "거짓"; }
} // namespace haneul