#pragma once
#include <string>
#include <variant>

#include "Dumpable.h"

namespace haneul {
enum class Opcode : uint8_t {
  Push,
  Pop,
  Store,
  Load,
  PopName,
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

class Instruction : public Dumpable {
public:
  using OperandType = std::variant<std::string, uint64_t>;
  Instruction(uint32_t line_number, Opcode opcode, OperandType operand)
      : line_number_(line_number), opcode_(opcode), operand_(operand) {}

  void dump() override;

private:
  uint32_t line_number_;
  Opcode opcode_;
  OperandType operand_;
};
} // namespace haneul