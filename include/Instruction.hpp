#pragma once
#include <string>
#include <vector>

#include "Dumpable.hpp"

namespace haneul {
enum class Opcode : uint8_t {
  Push,
  Pop,
  Load,
  StoreGlobal,
  LoadGlobal,
  Call,
  Jmp,
  PopJmpIfFalse,
  Add,
  Subtract,
  Multiply,
  Divide,
  Mod,
  Equal,
  LessThan,
  GreaterThan,
  Negate
};

class Instruction final : public Dumpable {
public:
  Instruction(uint32_t line_number, Opcode opcode, std::string operand)
      : line_number_(line_number), opcode_(opcode), string_operand_(operand) {}
  Instruction(uint32_t line_number, Opcode opcode, uint32_t operand)
      : line_number_(line_number), opcode_(opcode), integer_operand_(operand) {}
  Instruction(uint32_t line_number, Opcode opcode)
      : line_number_(line_number), opcode_(opcode) {}

  void dump() const override;

  Opcode get_opcode();
  std::string get_string_operand();
  uint64_t get_integer_operand();

private:
  uint32_t line_number_;
  Opcode opcode_;

  std::string string_operand_ = "";
  uint32_t integer_operand_ = 0;
};

using Code = std::vector<Instruction>;

} // namespace haneul