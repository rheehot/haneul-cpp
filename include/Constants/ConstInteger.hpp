#include "Constant.hpp"
#include "Value.hpp"

namespace haneul {
class ConstInteger : public Constant, public Value<int64_t> {

public:
  ConstInteger(ValueType value)
      : Constant(ConstantType::Integer), Value(value) {}

  Constant operator+(ConstantPtr other) const override;
  Constant operator-(ConstantPtr other) const override;
  Constant operator*(ConstantPtr other) const override;
  Constant operator/(ConstantPtr other) const override;
  Constant operator%(ConstantPtr other) const override;
  Constant operator==(ConstantPtr other) const override;
  Constant operator<(ConstantPtr other) const override;
  Constant operator>(ConstantPtr other) const override;

  Constant operator-() const override;
  std::string show() const override;
};
} // namespace haneul