#include "Constants/ConstChar.hpp"
#include "Constants/ConstBoolean.hpp"

#include "Util.hpp"

namespace haneul {

Constant ConstChar::operator==(ConstantPtr other) const {
  switch (other->get_type()) {
  case ConstantType::Char: {
    auto derived = dynamic_cast<const ConstChar *>(other);
    return ConstBoolean(this->value == derived->value);
  }
  default:
    return ConstBoolean(false);
  }
}

std::string ConstChar::show() const {
  return util::char32_to_string(this->value);
}

} // namespace haneul