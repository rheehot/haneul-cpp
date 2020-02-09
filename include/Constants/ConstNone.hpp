#include "Constant.hpp"
#include "Value.hpp"

namespace haneul {
class ConstNone : public Constant {
public:
  ConstNone() : Constant(ConstantType::None) {}

  ConstantPtr operator==(ConstantRawPtr other) const override;
  std::string show() const override;

  void dump() const override;
};
} // namespace haneul