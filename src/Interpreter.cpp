#include "Interpreter.hpp"

namespace haneul {

Interpreter::Interpreter(ConstantList &&const_table,
                         SymbolTable &&symbol_table) {
  call_stack_.push(StackFrame{std::move(const_table)});
  symbol_table_ = std::move(symbol_table);
}

} // namespace haneul