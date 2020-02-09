#include "Constant.hpp"
#include "Value.hpp"

namespace haneul {
class ConstReal : public Constant, public Value<double> {
public:
  ConstReal(ValueType value) : Constant(ConstantType::Real), Value(value) {}

  ConstantPtr operator+(ConstantRawPtr other) const override;
  ConstantPtr operator-(ConstantRawPtr other) const override;
  ConstantPtr operator*(ConstantRawPtr other) const override;
  ConstantPtr operator/(ConstantRawPtr other) const override;
  ConstantPtr operator==(ConstantRawPtr other) const override;
  ConstantPtr operator<(ConstantRawPtr other) const override;
  ConstantPtr operator>(ConstantRawPtr other) const override;

  ConstantPtr operator-() const override;
  std::string show() const override;

  void dump() const override;
};
} // namespace haneul