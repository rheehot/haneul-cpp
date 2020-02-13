#include <iostream>

#include "Instruction.hpp"
#include "magic_enum.hpp"

namespace haneul {
void Instruction::dump() const {
  std::cout << this->line_number_ << " | Inst."
            << magic_enum::enum_name(this->opcode_);
  std::cout << ' ' << this->integer_operand_;
  std::cout << " \"" << this->string_operand_ << "\"";
}

Opcode Instruction::get_opcode() const { return this->opcode_; }

const std::string &Instruction::get_string_operand() const {
  return this->string_operand_;
}
uint32_t Instruction::get_integer_operand() const {
  return this->integer_operand_;
}

} // namespace haneul