#include <algorithm>
#include <iostream>

#include "Constants/ConstBoolean.hpp"
#include "Constants/ConstFunc.hpp"
#include "Interpreter.hpp"

namespace haneul {

Interpreter::Interpreter(const SymbolTable &symbol_table) {
  this->symbol_table_ = symbol_table;
  this->stack_.reserve(250000);
}

ConstantPtr Interpreter::pop_move() {
  auto result = std::move(stack_.back());
  stack_.pop_back();
  return result;
}

void Interpreter::run(const StackFrame &frame) {
  for (auto it = frame.begin; it != frame.end; ++it) {
    const auto current_inst = *it;
    // current_inst.dump();

    const auto opcode = current_inst.get_opcode();
    switch (opcode) {
    case Opcode::Push: {
      const auto index = current_inst.get_integer_operand();
      stack_.push_back(frame.const_table[index]);
      break;
    }

    case Opcode::Pop:
      stack_.pop_back();
      break;

    case Opcode::Load: {
      const auto offset = current_inst.get_integer_operand();
      stack_.push_back(this->stack_[frame.slot_start + offset]);

      break;
    }

    case Opcode::LoadGlobal: {
      const auto symbol = current_inst.get_string_operand();
      stack_.push_back(symbol_table_.at(symbol));

      break;
    }

    case Opcode::StoreGlobal: {
      const auto symbol = current_inst.get_string_operand();
      symbol_table_[symbol] = this->pop_move();

      break;
    }

    case Opcode::Call: {
      const auto given_arity = current_inst.get_integer_operand();

      const auto callee = this->pop_move();

      if (callee->type != ConstantType::Function) {
        throw TypeException(type_to_string(callee->type) +
                            " 타입의 값은 호출 가능하지 않습니다.");
      }

      const auto func_constant = static_cast<const ConstFunc *>(callee.get());
      const auto actual_arity = func_constant->arity();

      if (given_arity != actual_arity) {
        throw InterpreterException("이 함수는 " + std::to_string(actual_arity) +
                                   "개의 인수를 받지만 " +
                                   std::to_string(given_arity) +
                                   "개의 인수가 주어졌습니다.");
      }

      if (std::holds_alternative<FuncObject>(func_constant->value)) {
        const auto func_object = std::get<FuncObject>(func_constant->value);

        this->run(
            StackFrame{func_object.const_table(), func_object.code().cbegin(),
                       func_object.code().cend(), stack_.size() - given_arity});

        const auto result = this->pop_move();

        for (std::size_t i = 0; i < given_arity; i++) {
          stack_.pop_back();
        }

        stack_.push_back(std::move(result));
      } else {
        const auto native_func = std::get<NativeFunc>(func_constant->value);

        std::vector<ConstantPtr> args;

        for (std::size_t i = 0; i < given_arity; i++) {
          args.push_back(this->pop_move());
        }

        const auto result = native_func.func()(args);

        stack_.push_back(result);
      }

      break;
    }

    case Opcode::Jmp: {
      it = frame.begin + current_inst.get_integer_operand() - 1;
      break;
    }

    case Opcode::PopJmpIfFalse: {
      const auto object = this->pop_move();

      if (object->type == ConstantType::Boolean) {
        const auto value =
            static_cast<const ConstBoolean *>(object.get())->value;

        if (!value) {
          it = frame.begin + current_inst.get_integer_operand() - 1;
        }
      } else {
        throw TypeException("여기에는 참 또는 거짓 타입을 필요로 합니다.");
      }

      break;
    }

    case Opcode::Negate: {
      const auto object = this->pop_move();

      stack_.push_back(
          -(*object)); // FIX: Boolean에 대한 negate 연산은 분리되어야함.
      break;
    }

    default: { // 이항 연산 인스트럭션들
      const auto rhs_ptr = this->pop_move();
      const auto lhs_ptr = this->pop_move();

      const auto &lhs = *lhs_ptr;
      const auto &rhs = rhs_ptr.get();

      switch (opcode) {
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

  // if (!stack_.empty())
  //   stack_.back()->dump();
}
} // namespace haneul