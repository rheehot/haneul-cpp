#include <iostream>

#include "Constant.hpp"

namespace haneul {
std::string typeto_string(const ConstantType &type) {
  switch (type) {
  case ConstantType::None:
    return "(없음)";
  case ConstantType::Integer:
    return "정수";
  case ConstantType::Boolean:
    return "부울";
  case ConstantType::Real:
    return "실수";
  case ConstantType::Char:
    return "문자";
  }
}

TypeException make_binary_typeexception(ConstantType lhs, ConstantType rhs,
                                        const std::string &operation) {
  return TypeException(typeto_string(lhs) + "와(과) " + typeto_string(rhs) +
                       "은(는) " + operation + " 연산을 지원하지 않습니다.");
}
TypeException make_unary_typeexception(ConstantType type,
                                       const std::string &operation) {

  return TypeException(typeto_string(type) + "은(는) " + operation +
                       " 연산을 지원하지 않습니다.");
}

ConstantPtr Constant::operator+(ConstantRawPtr other) const {
  throw make_binary_typeexception(this->type, other->type, "더하기");
}

ConstantPtr Constant::operator-(ConstantRawPtr other) const {
  throw make_binary_typeexception(this->type, other->type, "빼기");
}

ConstantPtr Constant::operator*(ConstantRawPtr other) const {
  throw make_binary_typeexception(this->type, other->type, "곱하기");
}

ConstantPtr Constant::operator/(ConstantRawPtr other) const {
  throw make_binary_typeexception(this->type, other->type, "나누기");
}

ConstantPtr Constant::operator%(ConstantRawPtr other) const {
  throw make_binary_typeexception(this->type, other->type, "나머지");
}

ConstantPtr Constant::operator==(ConstantRawPtr other) const {
  throw make_binary_typeexception(this->type, other->type, "비교");
}

ConstantPtr Constant::operator<(ConstantRawPtr other) const {
  throw make_binary_typeexception(this->type, other->type, "대소 비교");
}

ConstantPtr Constant::operator>(ConstantRawPtr other) const {
  throw make_binary_typeexception(this->type, other->type, "대소 비교");
}

ConstantPtr Constant::operator-() const {
  throw make_unary_typeexception(this->type, "부호 반전");
}

std::string Constant::show() const {
  throw make_unary_typeexception(this->type, "문자열화");
}

void Constant::dump() const { std::cout << "(구현 안됨)" << std::endl; }
} // namespace haneul