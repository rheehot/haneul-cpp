#include <bitset>
#include <cmath>
#include <fstream>
#include <iostream>

#include "Parser.hpp"
#include "Util.hpp"

#include "Constants/ConstBoolean.hpp"
#include "Constants/ConstChar.hpp"
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

Instruction Parser::parse_instruction() {
  auto line_number = this->consume<uint32_t>();
  auto opcode_index = this->consume<uint8_t>();

  auto opcode = static_cast<Opcode>(opcode_index);
  Instruction::OperandType operand;

  switch (opcode) {
  case Opcode::Push:
  case Opcode::Call:
  case Opcode::Jmp:
  case Opcode::PopJmpIfFalse: // 정수형 operand를 가지는 인스트럭션들
    operand = this->consume<uint32_t>();
    break;

  case Opcode::Store:
  case Opcode::Load: // 문자열 operand를 가지는 인스트럭션들
    operand = this->parse_string();
    break;

  default:
    operand = std::monostate();
  }

  return Instruction(line_number, opcode, operand);
}

ConstantPtr Parser::parse_constant() {
  auto constant_type_index = this->consume<uint8_t>();
  auto constant_type = static_cast<ConstantType>(constant_type_index);

  switch (constant_type) {
  case ConstantType::None:
    return std::make_unique<ConstNone>();
  case ConstantType::Integer:
    return std::make_unique<ConstInteger>(this->parse_integer());
  case ConstantType::Real:
    return std::make_unique<ConstReal>(this->parse_double());
  case ConstantType::Char:
    return std::make_unique<ConstChar>(this->parse_char());
  case ConstantType::Boolean:
    return std::make_unique<ConstBoolean>(this->parse_boolean());
  }
}
} // namespace haneul