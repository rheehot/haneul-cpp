#include <iostream>

#include "Constant.hpp"
#include "Constants/ConstBoolean.hpp"
#include "Constants/ConstChar.hpp"

#include "Util.hpp"

namespace haneul {

ConstantPtr ConstChar::operator==(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Char: {
    auto derived = static_cast<const ConstChar *>(other);
    return std::make_unique<ConstBoolean>(this->value == derived->value);
  }
  default:
    return std::make_unique<ConstBoolean>(false);
  }
}

ConstantPtr ConstChar::operator<(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Char: {
    auto derived = static_cast<const ConstChar *>(other);
    return std::make_unique<ConstBoolean>(this->value < derived->value);
  }
  default:
    return Constant::operator<(other);
  }
}

ConstantPtr ConstChar::operator>(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Char: {
    auto derived = static_cast<const ConstChar *>(other);
    return std::make_unique<ConstBoolean>(this->value > derived->value);
  }
  default:
    return Constant::operator>(other);
  }
}

std::string ConstChar::show() const {
  return util::char32_to_string(this->value);
}

void ConstChar::dump() const {
  std::cout << "ConstChar('" << util::char32_to_string(this->value) << "')"
            << std::endl;
}

} // namespace haneul