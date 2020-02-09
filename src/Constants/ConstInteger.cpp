#include <iostream>

#include "Constant.hpp"
#include "Constants/ConstBoolean.hpp"
#include "Constants/ConstInteger.hpp"
#include "Constants/ConstReal.hpp"

namespace haneul {
ConstantPtr ConstInteger::operator+(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Integer: {
    auto derived = static_cast<const ConstInteger *>(other);
    return std::make_unique<ConstInteger>(this->value + derived->value);
  }
  case ConstantType::Real: {
    auto derived = static_cast<const ConstReal *>(other);
    return std::make_unique<ConstReal>(this->value + derived->value);
  }
  default:
    return Constant::operator+(other);
  }
}

ConstantPtr ConstInteger::operator-(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Integer: {
    auto derived = static_cast<const ConstInteger *>(other);
    return std::make_unique<ConstInteger>(this->value - derived->value);
  }
  case ConstantType::Real: {
    auto derived = static_cast<const ConstReal *>(other);
    return std::make_unique<ConstReal>(this->value - derived->value);
  }
  default:
    return Constant::operator-(other);
  }
}

ConstantPtr ConstInteger::operator*(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Integer: {
    auto derived = static_cast<const ConstInteger *>(other);
    return std::make_unique<ConstInteger>(this->value * derived->value);
  }
  case ConstantType::Real: {
    auto derived = static_cast<const ConstReal *>(other);
    return std::make_unique<ConstReal>(this->value * derived->value);
  }
  default:
    return Constant::operator*(other);
  }
}

ConstantPtr ConstInteger::operator/(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Integer: {
    auto derived = static_cast<const ConstInteger *>(other);
    return std::make_unique<ConstInteger>(this->value / derived->value);
  }
  case ConstantType::Real: {
    auto derived = static_cast<const ConstReal *>(other);
    return std::make_unique<ConstReal>(this->value / derived->value);
  }
  default:
    return Constant::operator/(other);
  }
}

ConstantPtr ConstInteger::operator%(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Integer: {
    auto derived = static_cast<const ConstInteger *>(other);
    return std::make_unique<ConstInteger>(this->value % derived->value);
  }
  default:
    return Constant::operator%(other);
  }
}

ConstantPtr ConstInteger::operator==(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Integer: {
    auto derived = static_cast<const ConstInteger *>(other);
    return std::make_unique<ConstBoolean>(this->value == derived->value);
  }
  default:
    return Constant::operator==(other);
  }
}

ConstantPtr ConstInteger::operator<(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Integer: {
    auto derived = static_cast<const ConstInteger *>(other);
    return std::make_unique<ConstBoolean>(this->value < derived->value);
  }
  case ConstantType::Real: {
    auto derived = static_cast<const ConstReal *>(other);
    return std::make_unique<ConstBoolean>(this->value < derived->value);
  }
  default:
    return Constant::operator<(other);
  }
}

ConstantPtr ConstInteger::operator>(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Integer: {
    auto derived = static_cast<const ConstInteger *>(other);
    return std::make_unique<ConstBoolean>(this->value > derived->value);
  }
  case ConstantType::Real: {
    auto derived = static_cast<const ConstReal *>(other);
    return std::make_unique<ConstBoolean>(this->value > derived->value);
  }
  default:
    return Constant::operator>(other);
  }
}

ConstantPtr ConstInteger::operator-() const {
  return std::make_unique<ConstInteger>(-this->value);
}
std::string ConstInteger::show() const { return std::to_string(this->value); }

void ConstInteger::dump() const {
  std::cout << "ConstInteger(" << this->value << ")" << std::endl;
}
} // namespace haneul