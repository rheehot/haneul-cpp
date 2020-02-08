#include "Constant.hpp"

namespace haneul {
std::string type_to_string(const ConstantType &type) {
  switch (type) {
  case ConstantType::None:
    return "없음";
  case ConstantType::Integer:
    return "정수";
  }
}

Constant Constant::operator+(const Constant &other) {
  throw make_binary_type_exception(this->type_, other.type_, "더하기");
}

Constant Constant::operator-(const Constant &other) {
  throw make_binary_type_exception(this->type_, other.type_, "빼기");
}

Constant Constant::operator*(const Constant &other) {
  throw make_binary_type_exception(this->type_, other.type_, "곱하기");
}

Constant Constant::operator/(const Constant &other) {
  throw make_binary_type_exception(this->type_, other.type_, "나누기");
}

Constant Constant::operator%(const Constant &other) {
  throw make_binary_type_exception(this->type_, other.type_, "나머지");
}

Constant Constant::operator==(const Constant &other) {
  throw make_binary_type_exception(this->type_, other.type_, "비교");
}

Constant Constant::operator<(const Constant &other) {
  throw make_binary_type_exception(this->type_, other.type_, "대소 비교");
}

Constant Constant::operator>(const Constant &other) {
  throw make_binary_type_exception(this->type_, other.type_, "대소 비교");
}

Constant Constant::operator-() {
  throw make_unary_type_exception(this->type_, "부호 반전");
}

std::string Constant::show() {
  throw make_unary_type_exception(this->type_, "문자열화");
}
} // namespace haneul