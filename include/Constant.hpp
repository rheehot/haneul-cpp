#pragma once
#include <memory>
#include <string>

#include "Exception.hpp"

namespace haneul {
enum class ConstantType { None, Integer };

std::string type_to_string(ConstantType type);
TypeException make_binary_type_exception(ConstantType lhs, ConstantType rhs,
                                         const std::string &operation);
TypeException make_unary_type_exception(ConstantType type,
                                        const std::string &operation);

class Constant {
private:
  using ConstantPtr = const std::unique_ptr<Constant> &;
  const ConstantType type_;

public:
  Constant(ConstantType type) : type_(type) {}

  virtual Constant operator+(const Constant &other);
  virtual Constant operator-(const Constant &other);
  virtual Constant operator*(const Constant &other);
  virtual Constant operator/(const Constant &other);
  virtual Constant operator%(const Constant &other);
  virtual Constant operator==(const Constant &other);
  virtual Constant operator<(const Constant &other);
  virtual Constant operator>(const Constant &other);

  virtual Constant operator-();
  virtual std::string show();
};
} // namespace haneul