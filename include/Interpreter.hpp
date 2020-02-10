#pragma once
#include <map>
#include <stack>
#include <string>

#include "Constant.hpp"
#include "Instruction.hpp"

namespace haneul {
struct StackFrame final {
  ConstantList const_table;
};

class Interpreter final {
public:
  using SymbolTable = std::multimap<std::string, ConstantPtr>;

private:
  std::stack<StackFrame> call_stack_;
  SymbolTable symbol_table_;

public:
  Interpreter(ConstantList &&const_table, SymbolTable &&symbol_table);

  void run(const Code &code);
};
} // namespace haneul