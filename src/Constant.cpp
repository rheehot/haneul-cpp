#include "Constant.hpp"

namespace haneul {
std::string type_to_string(const ConstantType &type) {
  switch (type) {
  case ConstantType::None:
    return "(없음)";
  case ConstantType::Integer:
    return "정수";
  case ConstantType::Boolean:
    return "부울";
  }
}

TypeException make_binary_type_exception(ConstantType lhs, ConstantType rhs,
                                         const std::string &operation) {
  return TypeException(type_to_string(lhs) + "와(과) " + type_to_string(rhs) +
                       "은(는) " + operation + " 연산을 지원하지 않습니다.");
}
TypeException make_unary_type_exception(ConstantType type,
                                        const std::string &operation) {

  return TypeException(type_to_string(type) + "은(는) " + operation +
                       " 연산을 지원하지 않습니다.");
}

Constant Constant::operator+(ConstantPtr other) const {
  throw make_binary_type_exception(this->type_, other->type_, "더하기");
}

Constant Constant::operator-(ConstantPtr other) const {
  throw make_binary_type_exception(this->type_, other->type_, "빼기");
}

Constant Constant::operator*(ConstantPtr other) const {
  throw make_binary_type_exception(this->type_, other->type_, "곱하기");
}

Constant Constant::operator/(ConstantPtr other) const {
  throw make_binary_type_exception(this->type_, other->type_, "나누기");
}

Constant Constant::operator%(ConstantPtr other) const {
  throw make_binary_type_exception(this->type_, other->type_, "나머지");
}

Constant Constant::operator==(ConstantPtr other) const {
  throw make_binary_type_exception(this->type_, other->type_, "비교");
}

Constant Constant::operator<(ConstantPtr other) const {
  throw make_binary_type_exception(this->type_, other->type_, "대소 비교");
}

Constant Constant::operator>(ConstantPtr other) const {
  throw make_binary_type_exception(this->type_, other->type_, "대소 비교");
}

Constant Constant::operator-() const {
  throw make_unary_type_exception(this->type_, "부호 반전");
}

std::string Constant::show() const {
  throw make_unary_type_exception(this->type_, "문자열화");
}
} // namespace haneul