#include "Constants/ConstNone.hpp"
#include "Constants/ConstBoolean.hpp"

namespace haneul {
Constant ConstNone::operator==(ConstantPtr other) const {
  switch (other->type) {
  case ConstantType::None: {
    return ConstBoolean(true);
  }
  default:
    return ConstBoolean(false);
  }
}

std::string ConstNone::show() const { return "(없음)"; }
} // namespace haneul