#pragma once
#include <string>
#include <variant>
#include <vector>

#include "Dumpable.hpp"

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

class Instruction final : public Dumpable {
public:
  using OperandType = std::variant<std::monostate, std::string, uint64_t>;
  Instruction(uint32_t line_number, Opcode opcode, OperandType operand)
      : line_number_(line_number), opcode_(opcode), operand_(operand) {}

  void dump() const override;

private:
  uint32_t line_number_;
  Opcode opcode_;
  OperandType operand_;
};

using Code = std::vector<Instruction>;

} // namespace haneul