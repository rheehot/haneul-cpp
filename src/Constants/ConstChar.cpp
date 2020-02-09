#include "Constants/ConstChar.hpp"
#include "Constants/ConstBoolean.hpp"

#include "Util.hpp"

namespace haneul {

Constant ConstChar::operator==(ConstantPtr other) const {
  switch (other->type) {
  case ConstantType::Char: {
    auto derived = dynamic_cast<const ConstChar *>(other);
    return ConstBoolean(this->value == derived->value);
  }
  default:
    return ConstBoolean(false);
  }
}

Constant ConstChar::operator<(ConstantPtr other) const {
  switch (other->type) {
  case ConstantType::Char: {
    auto derived = dynamic_cast<const ConstChar *>(other);
    return ConstBoolean(this->value < derived->value);
  }
  default:
    throw make_binary_type_exception(this->type, other->type, "대소 비교");
  }
}

Constant ConstChar::operator>(ConstantPtr other) const {
  switch (other->type) {
  case ConstantType::Char: {
    auto derived = dynamic_cast<const ConstChar *>(other);
    return ConstBoolean(this->value > derived->value);
  }
  default:
    throw make_binary_type_exception(this->type, other->type, "대소 비교");
  }
}

std::string ConstChar::show() const {
  return util::char32_to_string(this->value);
}

} // namespace haneul