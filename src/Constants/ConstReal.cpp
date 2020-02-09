#include "Constants/ConstReal.hpp"
#include "Constants/ConstBoolean.hpp"
#include "Constants/ConstInteger.hpp"

namespace haneul {
Constant ConstReal::operator+(ConstantPtr other) const {
  switch (other->type) {
  case ConstantType::Real: {
    auto derived = dynamic_cast<const ConstReal *>(other);
    return ConstReal(this->value + derived->value);
  }
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstReal(this->value + derived->value);
  }
  default:
    throw make_binary_type_exception(this->type, other->type, "더하기");
  }
}

Constant ConstReal::operator-(ConstantPtr other) const {
  switch (other->type) {
  case ConstantType::Real: {
    auto derived = dynamic_cast<const ConstReal *>(other);
    return ConstReal(this->value - derived->value);
  }
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstReal(this->value - derived->value);
  }
  default:
    throw make_binary_type_exception(this->type, other->type, "빼기");
  }
}

Constant ConstReal::operator*(ConstantPtr other) const {
  switch (other->type) {
  case ConstantType::Real: {
    auto derived = dynamic_cast<const ConstReal *>(other);
    return ConstReal(this->value * derived->value);
  }
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstReal(this->value * derived->value);
  }
  default:
    throw make_binary_type_exception(this->type, other->type, "곱하기");
  }
}

Constant ConstReal::operator/(ConstantPtr other) const {
  switch (other->type) {
  case ConstantType::Real: {
    auto derived = dynamic_cast<const ConstReal *>(other);
    return ConstReal(this->value / derived->value);
  }
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstReal(this->value / derived->value);
  }
  default:
    throw make_binary_type_exception(this->type, other->type, "나누기");
  }
}

Constant ConstReal::operator==(ConstantPtr other) const {
  switch (other->type) {
  case ConstantType::Real: {
    auto derived = dynamic_cast<const ConstReal *>(other);
    return ConstBoolean(this->value == derived->value);
  }
  default:
    return ConstBoolean(false);
  }
}

Constant ConstReal::operator<(ConstantPtr other) const {
  switch (other->type) {
  case ConstantType::Real: {
    auto derived = dynamic_cast<const ConstReal *>(other);
    return ConstBoolean(this->value < derived->value);
  }
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstBoolean(this->value < derived->value);
  }
  default:
    throw make_binary_type_exception(this->type, other->type, "대소 비교");
  }
}

Constant ConstReal::operator>(ConstantPtr other) const {
  switch (other->type) {
  case ConstantType::Real: {
    auto derived = dynamic_cast<const ConstReal *>(other);
    return ConstBoolean(this->value > derived->value);
  }
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstBoolean(this->value > derived->value);
  }
  default:
    throw make_binary_type_exception(this->type, other->type, "대소 비교");
  }
}

Constant ConstReal::operator-() const { return ConstReal(-this->value); }
std::string ConstReal::show() const { return std::to_string(this->value); }
} // namespace haneul