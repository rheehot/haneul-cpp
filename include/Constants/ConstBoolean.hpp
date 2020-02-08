#include "Constant.hpp"

namespace haneul {
class ConstBoolean : public Constant {
private:
  using ValueType = bool;
  ValueType value_;

public:
  ConstBoolean(ValueType value)
      : Constant(ConstantType::Boolean), value_(value) {}

  Constant operator==(ConstantPtr other) const override;
  std::string show() const override;
};
} // namespace haneul