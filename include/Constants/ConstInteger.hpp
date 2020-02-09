#include <iostream>

#include "Constant.hpp"
#include "Value.hpp"

namespace haneul {
class ConstInteger : public Constant, public Value<int64_t> {
public:
  ConstInteger(ValueType value)
      : Constant(ConstantType::Integer), Value(value) {}

  ConstantPtr operator+(ConstantRawPtr other) const override;
  ConstantPtr operator-(ConstantRawPtr other) const override;
  ConstantPtr operator*(ConstantRawPtr other) const override;
  ConstantPtr operator/(ConstantRawPtr other) const override;
  ConstantPtr operator%(ConstantRawPtr other) const override;
  ConstantPtr operator==(ConstantRawPtr other) const override;
  ConstantPtr operator<(ConstantRawPtr other) const override;
  ConstantPtr operator>(ConstantRawPtr other) const override;

  ConstantPtr operator-() const override;
  std::string show() const override;

  void dump() const override;
};
} // namespace haneul