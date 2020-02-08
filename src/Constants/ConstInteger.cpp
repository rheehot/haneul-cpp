#include "Constants/ConstInteger.hpp"
#include "Constants/ConstBoolean.hpp"
#include "Constants/ConstReal.hpp"

namespace haneul {
Constant ConstInteger::operator+(ConstantPtr other) const {
  switch (other->get_type()) {
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstInteger(this->value + derived->value);
  }
  case ConstantType::Real: {
    auto derived = dynamic_cast<const ConstReal *>(other);
    return ConstReal(this->value + derived->value);
  }
  default:
    throw make_binary_type_exception(this->type_, other->get_type(), "더하기");
  }
}

Constant ConstInteger::operator-(ConstantPtr other) const {
  switch (other->get_type()) {
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstInteger(this->value - derived->value);
  }
  case ConstantType::Real: {
    auto derived = dynamic_cast<const ConstReal *>(other);
    return ConstReal(this->value - derived->value);
  }
  default:
    throw make_binary_type_exception(this->type_, other->get_type(), "빼기");
  }
}

Constant ConstInteger::operator*(ConstantPtr other) const {
  switch (other->get_type()) {
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstInteger(this->value * derived->value);
  }
  case ConstantType::Real: {
    auto derived = dynamic_cast<const ConstReal *>(other);
    return ConstReal(this->value * derived->value);
  }
  default:
    throw make_binary_type_exception(this->type_, other->get_type(), "곱하기");
  }
}

Constant ConstInteger::operator/(ConstantPtr other) const {
  switch (other->get_type()) {
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstInteger(this->value / derived->value);
  }
  case ConstantType::Real: {
    auto derived = dynamic_cast<const ConstReal *>(other);
    return ConstReal(this->value / derived->value);
  }
  default:
    throw make_binary_type_exception(this->type_, other->get_type(), "나누기");
  }
}

Constant ConstInteger::operator%(ConstantPtr other) const {
  switch (other->get_type()) {
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstInteger(this->value % derived->value);
  }
  default:
    throw make_binary_type_exception(this->type_, other->get_type(), "나머지");
  }
}

Constant ConstInteger::operator==(ConstantPtr other) const {
  switch (other->get_type()) {
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstBoolean(this->value == derived->value);
  }
  default:
    return ConstBoolean(false);
  }
}

Constant ConstInteger::operator<(ConstantPtr other) const {
  switch (other->get_type()) {
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstBoolean(this->value < derived->value);
  }
  case ConstantType::Real: {
    auto derived = dynamic_cast<const ConstReal *>(other);
    return ConstBoolean(this->value < derived->value);
  }
  default:
    throw make_binary_type_exception(this->type_, other->get_type(),
                                     "대소 비교");
  }
}

Constant ConstInteger::operator>(ConstantPtr other) const {
  switch (other->get_type()) {
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstBoolean(this->value > derived->value);
  }
  case ConstantType::Real: {
    auto derived = dynamic_cast<const ConstReal *>(other);
    return ConstBoolean(this->value > derived->value);
  }
  default:
    throw make_binary_type_exception(this->type_, other->get_type(),
                                     "대소 비교");
  }
}

Constant ConstInteger::operator-() const { return ConstInteger(-this->value); }
std::string ConstInteger::show() const { return std::to_string(this->value); }
} // namespace haneul