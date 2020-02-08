#include "Constant.hpp"
#include "Value.hpp"

namespace haneul {
class ConstReal : public Constant, public Value<double> {
public:
  ConstReal(ValueType value) : Constant(ConstantType::Real), Value(value) {}

  Constant operator+(ConstantPtr other) const override;
  Constant operator-(ConstantPtr other) const override;
  Constant operator*(ConstantPtr other) const override;
  Constant operator/(ConstantPtr other) const override;
  Constant operator==(ConstantPtr other) const override;
  Constant operator<(ConstantPtr other) const override;
  Constant operator>(ConstantPtr other) const override;

  Constant operator-() const override;
  std::string show() const override;
};
} // namespace haneul