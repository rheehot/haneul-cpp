#pragma once
#include <string>
#include <variant>

namespace haneul {
enum class Opcode {
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

class Instruction {
public:
  using OperandType = std::variant<std::string, uint64_t>;
  Instruction(Opcode opcode, OperandType operand)
      : opcode_(opcode), operand_(operand) {}

private:
  Opcode opcode_;
  OperandType operand_;
};
} // namespace haneul