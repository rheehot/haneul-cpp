#include <iostream>

#include "Constant.hpp"
#include "Constants/ConstBoolean.hpp"
#include "Constants/ConstInteger.hpp"
#include "Constants/ConstReal.hpp"

namespace haneul {
ConstantPtr ConstReal::operator+(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Real: {
    auto derived = static_cast<const ConstReal *>(other);
    return std::make_shared<ConstReal>(this->value + derived->value);
  }
  case ConstantType::Integer: {
    auto derived = static_cast<const ConstInteger *>(other);
    return std::make_shared<ConstReal>(this->value + derived->value);
  }
  default:
    return Constant::operator+(other);
  }
}

ConstantPtr ConstReal::operator-(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Real: {
    auto derived = static_cast<const ConstReal *>(other);
    return std::make_shared<ConstReal>(this->value - derived->value);
  }
  case ConstantType::Integer: {
    auto derived = static_cast<const ConstInteger *>(other);
    return std::make_shared<ConstReal>(this->value - derived->value);
  }
  default:
    return Constant::operator-(other);
  }
}

ConstantPtr ConstReal::operator*(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Real: {
    auto derived = static_cast<const ConstReal *>(other);
    return std::make_shared<ConstReal>(this->value * derived->value);
  }
  case ConstantType::Integer: {
    auto derived = static_cast<const ConstInteger *>(other);
    return std::make_shared<ConstReal>(this->value * derived->value);
  }
  default:
    return Constant::operator*(other);
  }
}

ConstantPtr ConstReal::operator/(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Real: {
    auto derived = static_cast<const ConstReal *>(other);
    return std::make_shared<ConstReal>(this->value / derived->value);
  }
  case ConstantType::Integer: {
    auto derived = static_cast<const ConstInteger *>(other);
    return std::make_shared<ConstReal>(this->value / derived->value);
  }
  default:
    return Constant::operator/(other);
  }
}

ConstantPtr ConstReal::operator==(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Real: {
    auto derived = static_cast<const ConstReal *>(other);
    return std::make_shared<ConstBoolean>(this->value == derived->value);
  }
  default:
    return std::make_shared<ConstBoolean>(false);
  }
}

ConstantPtr ConstReal::operator<(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Real: {
    auto derived = static_cast<const ConstReal *>(other);
    return std::make_shared<ConstBoolean>(this->value < derived->value);
  }
  case ConstantType::Integer: {
    auto derived = static_cast<const ConstInteger *>(other);
    return std::make_shared<ConstBoolean>(this->value < derived->value);
  }
  default:
    return Constant::operator<(other);
  }
}

ConstantPtr ConstReal::operator>(ConstantRawPtr other) const {
  switch (other->type) {
  case ConstantType::Real: {
    auto derived = static_cast<const ConstReal *>(other);
    return std::make_shared<ConstBoolean>(this->value > derived->value);
  }
  case ConstantType::Integer: {
    auto derived = static_cast<const ConstInteger *>(other);
    return std::make_shared<ConstBoolean>(this->value > derived->value);
  }
  default:
    return Constant::operator>(other);
  }
}

ConstantPtr ConstReal::operator-() const {
  return std::make_shared<ConstReal>(-this->value);
}
std::string ConstReal::show() const { return std::to_string(this->value); }

void ConstReal::dump() const {
  std::cout << "ConstReal(" << this->value << ")" << std::endl;
}
} // namespace haneul