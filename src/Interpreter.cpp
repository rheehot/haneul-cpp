#include <algorithm>

#include "Constants/ConstFunc.hpp"
#include "Interpreter.hpp"

namespace haneul {

Interpreter::Interpreter(const ConstantList &const_table,
                         const SymbolTable &symbol_table) {
  this->call_stack_.push(StackFrame{const_table});
  this->symbol_table_ = symbol_table;
}

StackFrame Interpreter::current_frame() { return this->call_stack_.top(); }

void Interpreter::run(CodeIterator begin, CodeIterator end,
                      ConstantList const_table) {

  for (auto it = begin; it != end; ++it) {
    auto current_inst = *it;

    switch (current_inst.get_opcode()) {
    case Opcode::Push: {
      auto index = current_inst.get_integer_operand();
      stack_.push(const_table[index]);
      break;
    }

    case Opcode::Pop:
      stack_.pop();
      break;

    case Opcode::Store: {
      auto symbol = current_inst.get_string_operand();
      this->symbol_table_.emplace_back(symbol, stack_.top());
      stack_.pop();

      break;
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

      stack_.push(result->second);

      break;
    }

    case Opcode::PopName: {
      this->symbol_table_.pop_back();
      break;
    }

    case Opcode::Call: {
      auto given_arity = current_inst.get_integer_operand();
      std::vector<ConstantPtr> args;

      auto callee = stack_.top();
      stack_.pop();

      // for (std::size_t i = 0; i < given_arity; i++) {
      //   args.push_back(stack.top());
      //   stack.pop();
      // }

      if (callee->type == ConstantType::Function) {
        auto func_object = static_cast<const ConstFunc *>(callee.get())->value;
        auto actual_arity = func_object.arg_names.size();

        if (given_arity != actual_arity) {
          throw InterpreterException(
              "이 함수는 " + std::to_string(actual_arity) +
              "개의 인수를 받지만 " + std::to_string(given_arity) +
              "개의 인수가 주어졌습니다.");
        }

        this->run(func_object.code.cbegin(), func_object.code.cend(),
                  func_object.const_table);
      } else {
        throw TypeException(type_to_string(callee->type) +
                            " 타입의 값은 호출 가능하지 않습니다.");
      }
    }
    }
  }
}
} // namespace haneul