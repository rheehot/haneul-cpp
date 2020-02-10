#include <algorithm>

#include "Interpreter.hpp"

namespace haneul {

Interpreter::Interpreter(const ConstantList &const_table,
                         const SymbolTable &symbol_table) {
  this->call_stack_.push(StackFrame{const_table});
  this->symbol_table_ = symbol_table;
}

StackFrame Interpreter::current_frame() { return this->call_stack_.top(); }

void Interpreter::run(CodeIterator begin, CodeIterator end) {
  std::stack<ConstantPtr> stack;

  for (; begin != end; ++begin) {
    auto current_inst = *begin;
    switch (current_inst.get_opcode()) {
    case Opcode::Push: {
      auto index = current_inst.get_integer_operand();
      stack.push(this->current_frame().const_table[index]);
      break;
    }

    case Opcode::Pop:
      stack.pop();
      break;

    case Opcode::Store: {
      auto symbol = current_inst.get_string_operand();
      this->symbol_table_.insert(std::make_pair(symbol, stack.top()));
      stack.pop();
    }

    case Opcode::Load: {
      auto symbol = current_inst.get_string_operand();
      auto result =
          std::find_if(this->symbol_table_.rbegin(), this->symbol_table_.rend(),
                       [&symbol](auto x) { return x.first == symbol; });

      if (result == this->symbol_table_.rend()) {
        throw InterpreterException("식별자 '" + symbol +
                                   "'를 찾을 수 없습니다.");
      }

      stack.push(result->second);
    }
    }
  }
}
} // namespace haneul