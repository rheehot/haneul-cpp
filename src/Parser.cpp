#include <bitset>
#include <cmath>
#include <fstream>
#include <iostream>

#include "Parser.hpp"
#include "Util.hpp"

#include "Constants/ConstBoolean.hpp"
#include "Constants/ConstChar.hpp"
#include "Constants/ConstFunc.hpp"
#include "Constants/ConstInteger.hpp"
#include "Constants/ConstNone.hpp"
#include "Constants/ConstReal.hpp"

namespace haneul {
Parser::Parser(const std::string &input_file) {
  std::ifstream stream(input_file, std::ios::in | std::ios::binary);
  Parser::InputType content((std::istreambuf_iterator<char>(stream)),
                            std::istreambuf_iterator<char>());

  this->input_ = content;
}

template <class T> T Parser::peek(std::size_t n) {
  T result = 0;

  ;
  for (std::size_t i = 0; i < n; i++) {
    result += static_cast<T>(this->input_[this->pos_ + i]) << (8 * (n - i - 1));
  }

  return result;
}

template <class T> T Parser::consume(std::size_t n) {
  auto result = this->peek<T>(n);
  this->pos_ += n;
  return result;
}

template <> uint8_t Parser::consume<uint8_t>(std::size_t) {
  return this->input_[this->pos_++];
}

template <> int8_t Parser::consume<int8_t>(std::size_t) {
  return this->input_[this->pos_++];
}

int64_t Parser::parse_integer() { return this->consume<int64_t>(); }

double Parser::parse_double() {
  auto base = this->consume<int64_t>();
  auto exp = this->consume<int64_t>();

  return base * std::pow(2, exp);
}

char32_t Parser::parse_char() {
  auto head = this->peek<uint8_t>();
  std::size_t count = 0;

  if (head < 0x80) {
    count = 1;
  } else if (head < 0xE0) {
    count = 2;
  } else if (head < 0xF0) {
    count = 3;
  } else {
    count = 4;
  }

  return this->consume<char32_t>(count);
}

std::string Parser::parse_string() {
  auto count = this->consume<uint64_t>();

  std::string result = "";
  for (std::size_t i = 0; i < count; i++) {
    auto ch = this->parse_char();
    result += util::char32_to_string(ch);
  }

  return result;
}

bool Parser::parse_boolean() {
  auto value = this->consume<uint8_t>();
  return value == 1;
}

FuncObject Parser::parse_func_object() {
  auto const_table = this->parse_list([&] { return parse_constant(); });
  auto code = this->parse_list([&] { return parse_instruction(); });

  return FuncObject(code, const_table);
}

Instruction Parser::parse_instruction() {
  auto line_number = this->consume<uint32_t>();
  auto opcode_index = this->consume<uint8_t>();

  auto opcode = static_cast<Opcode>(opcode_index);

  switch (opcode) {
  case Opcode::Push:
  case Opcode::Call:
  case Opcode::Jmp:
  case Opcode::PopJmpIfFalse: // 정수형 operand를 가지는 인스트럭션들
  case Opcode::Load:
    return Instruction(line_number, opcode, this->consume<uint32_t>());

  case Opcode::LoadGlobal:
  case Opcode::StoreGlobal: // 문자열 operand를 가지는 인스트럭션들
    return Instruction(line_number, opcode, this->parse_string());

  default:
    return Instruction(line_number, opcode);
  }
}

ConstantPtr Parser::parse_constant() {
  auto constant_type_index = this->consume<uint8_t>();
  auto constant_type = static_cast<ConstantType>(constant_type_index);

  switch (constant_type) {
  case ConstantType::None:
    return std::make_shared<ConstNone>();
  case ConstantType::Integer:
    return std::make_shared<ConstInteger>(this->parse_integer());
  case ConstantType::Real:
    return std::make_shared<ConstReal>(this->parse_double());
  case ConstantType::Char:
    return std::make_shared<ConstChar>(this->parse_char());
  case ConstantType::Boolean:
    return std::make_shared<ConstBoolean>(this->parse_boolean());
  case ConstantType::Function:
    auto arity = this->consume<uint8_t>();
    return std::make_shared<ConstFunc>(arity, this->parse_func_object());
  }
}

std::pair<ConstantList, Code> Parser::parse_program() {
  auto const_table = this->parse_list([&] { return parse_constant(); });
  auto code = this->parse_list([&] { return parse_instruction(); });

  return std::make_pair(const_table, code);
}

template <class Functor>
std::vector<std::invoke_result_t<Functor>>
Parser::parse_list(Functor &&parse_func) {
  using ResultType = std::invoke_result_t<Functor>;
  static_assert(std::is_invocable_v<Functor>);

  auto count = this->consume<uint64_t>();
  std::vector<ResultType> result;

  for (std::size_t i = 0; i < count; i++) {
    result.push_back(std::forward<ResultType>(parse_func()));
  }

  return result;
}
} // namespace haneul