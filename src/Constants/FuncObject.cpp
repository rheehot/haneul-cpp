#include <iostream>

#include "Constants/FuncObject.hpp"

namespace haneul {
void FuncObject::dump() const {
  std::cout << "FuncObject(" << std::endl;
  std::cout << "const table: " << std::endl;
  for (const auto &c : this->const_table()) {
    std::cout << "   ";
    c->dump();
  }

  std::cout << "code: " << std::endl;
  for (auto inst : this->code()) {
    std::cout << "   ";
    inst.dump();
  }
  std::cout << ")" << std::endl;
}
} // namespace haneul