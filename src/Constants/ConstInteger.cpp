#include "Constants/ConstInteger.hpp"

namespace haneul {
Constant ConstInteger::operator+(ConstantPtr other) const {
  switch (other->get_type()) {
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstInteger(this->value_ + derived->value_);
  }
  default:
    throw make_binary_type_exception(this->type_, other->get_type(), "더하기");
  }
}

Constant ConstInteger::operator-(ConstantPtr other) const {
  switch (other->get_type()) {
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstInteger(this->value_ - derived->value_);
  }
  default:
    throw make_binary_type_exception(this->type_, other->get_type(), "빼기");
  }
}

Constant ConstInteger::operator*(ConstantPtr other) const {
  switch (other->get_type()) {
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstInteger(this->value_ * derived->value_);
  }
  default:
    throw make_binary_type_exception(this->type_, other->get_type(), "빼기");
  }
}

Constant ConstInteger::operator/(ConstantPtr other) const {
  switch (other->get_type()) {
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstInteger(this->value_ / derived->value_);
  }
  default:
    throw make_binary_type_exception(this->type_, other->get_type(), "빼기");
  }
}

Constant ConstInteger::operator%(ConstantPtr other) const {
  switch (other->get_type()) {
  case ConstantType::Integer: {
    auto derived = dynamic_cast<const ConstInteger *>(other);
    return ConstInteger(this->value_ % derived->value_);
  }
  default:
    throw make_binary_type_exception(this->type_, other->get_type(), "빼기");
  }
}

Constant ConstInteger::operator-() const { return ConstInteger(-this->value_); }
std::string ConstInteger::show() const { return std::to_string(this->value_); }
} // namespace haneul