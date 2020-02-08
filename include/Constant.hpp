#pragma once
#include <memory>
#include <string>

#include "Exception.hpp"

namespace haneul {
enum class ConstantType { None, Integer, Boolean, Real, Char };

TypeException make_binary_type_exception(ConstantType lhs, ConstantType rhs,
                                         const std::string &operation);
TypeException make_unary_type_exception(ConstantType type,
                                        const std::string &operation);

class Constant;

using ConstantPtr = const Constant *const;

class Constant {
protected:
  const ConstantType type_;

public:
  Constant(ConstantType type) : type_(type) {}

  ConstantType get_type() const noexcept { return this->type_; }

  virtual Constant operator+(ConstantPtr other) const;
  virtual Constant operator-(ConstantPtr other) const;
  virtual Constant operator*(ConstantPtr other) const;
  virtual Constant operator/(ConstantPtr other) const;
  virtual Constant operator%(ConstantPtr other) const;
  virtual Constant operator==(ConstantPtr other) const;
  virtual Constant operator<(ConstantPtr other) const;
  virtual Constant operator>(ConstantPtr other) const;

  virtual Constant operator-() const;
  virtual std::string show() const;
};

} // namespace haneul