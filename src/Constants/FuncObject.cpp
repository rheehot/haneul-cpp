#include <iostream>

#include "Constants/FuncObject.hpp"

namespace haneul {
void FuncObject::dump() const {
  std::cout << "FuncObject(" << std::endl;
  std::cout << "args: ";
  for (auto arg : this->arg_names_) {
    std::cout << arg << ", ";
  }
  std::cout << std::endl;

  std::cout << "const table: " << std::endl;
  for (const auto &c : this->const_table_) {
    std::cout << "   ";
    c->dump();
  }

  std::cout << "code: " << std::endl;
  for (auto inst : this->code_) {
    std::cout << "   ";
    inst.dump();
  }
  std::cout << ")" << std::endl;
}
} // namespace haneul