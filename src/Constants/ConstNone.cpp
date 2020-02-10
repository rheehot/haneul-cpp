#include <iostream>

#include "Constants/ConstBoolean.hpp"
#include "Constants/ConstNone.hpp"

namespace haneul {
ConstantPtr ConstNone::operator==(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::None: {
    return std::make_shared<ConstBoolean>(true);
  }
  default:
    return std::make_shared<ConstBoolean>(false);
  }
}

std::string ConstNone::show() const { return "(없음)"; }

void ConstNone::dump() const { std::cout << "ConstNone()" << std::endl; }
} // namespace haneul