#include <algorithm>
#include <iostream>

#include "Constants/ConstBoolean.hpp"
#include "Constants/ConstFunc.hpp"
#include "Interpreter.hpp"

namespace haneul {

Interpreter::Interpreter(const SymbolTable &symbol_table) {
  this->symbol_table_ = symbol_table;
}

void Interpreter::run(const StackFrame &frame) {
  for (auto it = frame.begin; it != frame.end; ++it) {
    auto current_inst = *it;
    // current_inst.dump();

    switch (current_inst.get_opcode()) {
    case Opcode::Push: {
      auto index = current_inst.get_integer_operand();
      stack_.push_back(frame.const_table[index]);
      break;
    }

    case Opcode::Pop:
      stack_.pop_back();
      break;

    case Opcode::Load: {
      auto offset = current_inst.get_integer_operand();
      auto result = this->stack_[frame.slot_start + offset];

      stack_.push_back(result);

      break;
    }

    case Opcode::LoadGlobal: {
      auto symbol = current_inst.get_string_operand();
      stack_.push_back(symbol_table_.at(symbol));

      break;
    }

    case Opcode::StoreGlobal: {
      auto symbol = current_inst.get_string_operand();
      symbol_table_[symbol] = stack_.back();
      stack_.pop_back();

      break;
    }

    case Opcode::Call: {
      auto given_arity = current_inst.get_integer_operand();

      auto callee = stack_.back();
      stack_.pop_back();

      if (callee->type == ConstantType::Function) {
        auto func_object = static_cast<const ConstFunc *>(callee.get())->value;
        auto actual_arity = func_object.arg_names().size();

        if (given_arity != actual_arity) {
          throw InterpreterException(
              "이 함수는 " + std::to_string(actual_arity) +
              "개의 인수를 받지만 " + std::to_string(given_arity) +
              "개의 인수가 주어졌습니다.");
        }

        this->run(
            StackFrame{func_object.const_table(), func_object.code().cbegin(),
                       func_object.code().cend(), stack_.size() - given_arity});

        auto result = stack_.back();

        for (std::size_t i = 0; i <= given_arity; i++) {
          stack_.pop_back();
        }

        stack_.push_back(result);
      } else {
        throw TypeException(type_to_string(callee->type) +
                            " 타입의 값은 호출 가능하지 않습니다.");
      }

      break;
    }

    case Opcode::Jmp: {
      it = frame.begin + current_inst.get_integer_operand() - 1;
      break;
    }

    case Opcode::PopJmpIfFalse: {
      auto object = stack_.back();
      stack_.pop_back();
      if (object->type == ConstantType::Boolean) {
        auto value = static_cast<const ConstBoolean *>(object.get())->value;

        if (!value) {
          it = frame.begin + current_inst.get_integer_operand() - 1;
        }
      } else {
        throw TypeException("여기에는 참 또는 거짓 타입을 필요로 합니다.");
      }

      break;
    }

    case Opcode::Negate: {
      auto object = stack_.back();
      stack_.pop_back();

      stack_.push_back(
          -(*object)); // FIX: Boolean에 대한 negate 연산은 분리되어야함.
      break;
    }

    default: { // 이항 연산 인스트럭션들
      auto rhs_ptr = stack_.back();
      stack_.pop_back();
      auto lhs_ptr = stack_.back();
      stack_.pop_back();

      const auto &lhs = *lhs_ptr;
      const auto &rhs = rhs_ptr.get();

      switch (current_inst.get_opcode()) {
      case Opcode::Add:
        stack_.push_back(lhs + rhs);
        break;
      case Opcode::Subtract:
        stack_.push_back(lhs - rhs);
        break;
      case Opcode::Multiply:
        stack_.push_back(lhs * rhs);
        break;
      case Opcode::Divide:
        stack_.push_back(lhs / rhs);
        break;
      case Opcode::Mod:
        stack_.push_back(lhs % rhs);
        break;
      case Opcode::Equal:
        stack_.push_back(lhs == rhs);
        break;
      case Opcode::LessThan:
        stack_.push_back(lhs < rhs);
        break;
      case Opcode::GreaterThan:
        stack_.push_back(lhs > rhs);
        break;
      }
    }
    }
  }
}
} // namespace haneul