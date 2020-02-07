#include "Insturction.hpp"

#include <iostream>

#include "magic_enum.hpp"

namespace haneul {
void Instruction::dump() {
  std::cout << this->line_number_ << " | Inst."
            << magic_enum::enum_name(this->opcode_);
  if (std::holds_alternative<uint64_t>(this->operand_)) {
    std::cout << ' ' << std::get<uint64_t>(this->operand_);
  } else if (std::holds_alternative<std::string>(this->operand_)) {
    std::cout << " \"" << std::get<std::string>(this->operand_) << "\"";
  }

  std::cout << std::endl;
}
} // namespace haneul