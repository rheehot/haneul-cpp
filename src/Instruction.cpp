#include "Insturction.h"

#include <iostream>

#include "magic_enum.hpp"

namespace haneul {
void Instruction::dump() {
  std::cout << "Instruction(" << this->line_number_ << ", "
            << magic_enum::enum_name(this->opcode_) << ")" << std::endl;
}
} // namespace haneul