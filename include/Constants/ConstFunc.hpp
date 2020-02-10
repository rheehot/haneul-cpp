#include "Constant.hpp"
#include "FuncObject.hpp"
#include "Instruction.hpp"
#include "Value.hpp"

namespace haneul {

class ConstFunc : public Constant, public Value<FuncObject> {
public:
  ConstFunc(ValueType &&value)
      : Constant(ConstantType::Function), Value(std::move(value)) {}

  void dump() const override;

  ConstFunc(ConstFunc &&) = default;
  ConstFunc(const ConstFunc &) = delete;
  ConstFunc &operator=(const ConstFunc &) = delete;
};

} // namespace haneul