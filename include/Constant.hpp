#pragma once
#include <memory>
#include <string>
#include <vector>

#include "Dumpable.hpp"
#include "Exception.hpp"

namespace haneul {
enum class ConstantType : uint8_t {
  None,
  Integer,
  Real,
  Char,
  Boolean,
  Function
};

std::string type_to_string(const ConstantType &type);

TypeException make_binary_type_exception(ConstantType lhs, ConstantType rhs,
                                         const std::string &operation);
TypeException make_unary_type_exception(ConstantType type,
                                        const std::string &operation);

class Constant;

using ConstantRawPtr = const Constant *const;
using ConstantPtr = std::shared_ptr<Constant>;
using ConstantList = std::vector<ConstantPtr>;

class Constant : public Dumpable {
public:
  const ConstantType type;
  Constant(ConstantType t) : type(t) {}
  virtual ~Constant() {}

  virtual ConstantPtr operator+(ConstantRawPtr other) const;
  virtual ConstantPtr operator-(ConstantRawPtr other) const;
  virtual ConstantPtr operator*(ConstantRawPtr other) const;
  virtual ConstantPtr operator/(ConstantRawPtr other) const;
  virtual ConstantPtr operator%(ConstantRawPtr other) const;
  virtual ConstantPtr operator==(ConstantRawPtr other) const;
  virtual ConstantPtr operator<(ConstantRawPtr other) const;
  virtual ConstantPtr operator>(ConstantRawPtr other) const;

  virtual ConstantPtr operator-() const;
  virtual std::string show() const;

  virtual void dump() const;
};

} // namespace haneul