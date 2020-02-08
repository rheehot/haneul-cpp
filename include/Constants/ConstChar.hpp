#include "Constant.hpp"
#include "Value.hpp"

namespace haneul {
class ConstChar : public Constant, public Value<char32_t> {
public:
  ConstChar(ValueType value) : Constant(ConstantType::Char), Value(value) {}

  Constant operator==(ConstantPtr other) const override;
  Constant operator<(ConstantPtr other) const override;
  Constant operator>(ConstantPtr other) const override;

  std::string show() const override;
};
} // namespace haneul