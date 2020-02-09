#include "Constant.hpp"
#include "Value.hpp"

namespace haneul {
class ConstNone : public Constant {
public:
  ConstNone() : Constant(ConstantType::None) {}

  Constant operator==(ConstantPtr other) const override;
  std::string show() const override;
};
} // namespace haneul