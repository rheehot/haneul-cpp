#include <iostream>

#include "Constants/ConstFunc.hpp"

namespace haneul {
void ConstFunc::dump() const {
  std::cout << "ConstFunc(~)" << std::endl;

  if (std::holds_alternative<FuncObject>(value))
    std::get<FuncObject>(this->value).dump();
}
} // namespace haneul