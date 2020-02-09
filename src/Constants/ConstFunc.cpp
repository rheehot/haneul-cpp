#include <iostream>

#include "Constants/ConstFunc.hpp"

namespace haneul {
void ConstFunc::dump() const {
  std::cout << "ConstFunc(~)" << std::endl;
  this->value.dump();
}
} // namespace haneul