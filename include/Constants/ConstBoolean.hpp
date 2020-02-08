#include "Constant.hpp"
#include "Value.hpp"

namespace haneul {
class ConstBoolean : public Constant, public Value<bool> {
public:
  ConstBoolean(ValueType value)
      : Constant(ConstantType::Boolean), Value(value) {}

  Constant operator==(ConstantPtr other) const override;
  std::string show() const override;
};
} // namespace haneul