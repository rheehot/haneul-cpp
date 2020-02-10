#include <iostream>

#include "Instruction.hpp"
#include "magic_enum.hpp"

namespace haneul {
void Instruction::dump() const {
  std::cout << this->line_number_ << " | Inst."
            << magic_enum::enum_name(this->opcode_);
  if (std::holds_alternative<uint64_t>(this->operand_)) {
    std::cout << ' ' << std::get<uint64_t>(this->operand_);
  } else if (std::holds_alternative<std::string>(this->operand_)) {
    std::cout << " \"" << std::get<std::string>(this->operand_) << "\"";
  }

  std::cout << std::endl;
}

Opcode Instruction::get_opcode() { return this->opcode_; }

std::string Instruction::get_string_operand() {
  return std::get<std::string>(this->operand_);
}

uint64_t Instruction::get_integer_operand() {
  return std::get<uint64_t>(this->operand_);
}

} // namespace haneul