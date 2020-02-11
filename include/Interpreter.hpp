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
  using SymbolTable = std::vector<std::pair<std::string, ConstantPtr>>;
  using CodeIterator = Code::const_iterator;

private:
  std::stack<StackFrame> call_stack_;
  SymbolTable symbol_table_;
  std::stack<ConstantPtr> stack_;

  StackFrame current_frame();

public:
  Interpreter(const ConstantList &const_table, const SymbolTable &symbol_table);

  void run(CodeIterator begin, CodeIterator end, ConstantList const_table);
};
} // namespace haneul