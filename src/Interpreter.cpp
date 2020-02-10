#include "Interpreter.hpp"

namespace haneul {

Interpreter::Interpreter(ConstantList &&const_table,
                         SymbolTable &&symbol_table) {
  this->call_stack_.push(StackFrame{std::move(const_table)});
  this->symbol_table_ = std::move(symbol_table);
}

StackFrame Interpreter::current_frame() {
  return std::move(this->call_stack_.top());
}

void Interpreter::run(CodeIterator begin, CodeIterator end) {
  std::stack<ConstantPtr> stack;

  for (; begin != end; ++begin) {
    auto current_inst = *begin;
    switch (current_inst.get_opcode()) {
    case Opcode::Push:
      auto index = current_inst.get_integer_operand();
      stack.push(std::move(this->current_frame().const_table[index]));
      break;
    }
  }
}
} // namespace haneul