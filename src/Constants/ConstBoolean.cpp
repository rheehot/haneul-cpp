#include <iostream>

#include "Constants/ConstBoolean.hpp"

namespace haneul {
ConstantPtr ConstBoolean::operator==(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Boolean: {
    auto derived = static_cast<const ConstBoolean *>(other);
    return std::make_shared<ConstBoolean>(this->value == derived->value);
  }
  default:
    return std::make_shared<ConstBoolean>(false);
  }
}

std::string ConstBoolean::show() const { return this->value ? "참" : "거짓"; }

void ConstBoolean::dump() const {
  std::cout << "ConstBoolean(" << this->value << ")" << std::endl;
}
} // namespace haneul