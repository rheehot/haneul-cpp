#include "Constant.hpp"
#include "Value.hpp"

namespace haneul {
class ConstChar : public Constant, public Value<char32_t> {
public:
  ConstChar(ValueType value) : Constant(ConstantType::Char), Value(value) {}

  ConstantPtr operator==(ConstantRawPtr other) const override;
  ConstantPtr operator<(ConstantRawPtr other) const override;
  ConstantPtr operator>(ConstantRawPtr other) const override;

  std::string show() const override;

  void dump() const override;
};
} // namespace haneul