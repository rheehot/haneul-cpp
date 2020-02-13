#pragma once
#include <map>
#include <stack>
#include <string>

#include "Constant.hpp"
#include "Instruction.hpp"

namespace haneul {
struct StackFrame;

class Interpreter final {
public:
  using SymbolTable = std::map<std::string, ConstantPtr>;
  using CodeIterator = Code::const_iterator;

private:
  SymbolTable symbol_table_;
  std::vector<ConstantPtr> stack_;

public:
  Interpreter(const SymbolTable &symbol_table);

  void run(const StackFrame &frame);
};

struct StackFrame final {
  ConstantList const_table;
  Interpreter::CodeIterator begin;
  Interpreter::CodeIterator end;
  std::size_t slot_start;
};

} // namespace haneul