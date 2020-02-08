#include "Constant.hpp"

namespace haneul {
class ConstInteger : public Constant {
private:
  using ValueType = int64_t;
  ValueType value_;

public:
  ConstInteger(ValueType value)
      : Constant(ConstantType::Integer), value_(value) {}

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