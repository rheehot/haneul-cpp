#include "Constant.hpp"

namespace haneul {
class ConstReal : public Constant {
private:
  using ValueType = double;
  ValueType value_;

public:
  ConstReal(ValueType value) : Constant(ConstantType::Real), value_(value) {}

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