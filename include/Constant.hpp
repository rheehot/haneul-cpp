#pragma once
#include <memory>
#include <string>

#include "Exception.hpp"

namespace haneul {
enum class ConstantType : uint8_t { None, Integer, Real, Char, Boolean };

TypeException make_binary_type_exception(ConstantType lhs, ConstantType rhs,
                                         const std::string &operation);
TypeException make_unary_type_exception(ConstantType type,
                                        const std::string &operation);

class Constant;

using ConstantPtr = const Constant *const;

class Constant {
protected:
public:
  const ConstantType type;
  Constant(ConstantType t) : type(t) {}

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