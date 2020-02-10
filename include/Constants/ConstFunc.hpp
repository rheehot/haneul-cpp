#include "Constant.hpp"
#include "FuncObject.hpp"
#include "Instruction.hpp"
#include "Value.hpp"

namespace haneul {

class ConstFunc : public Constant, public Value<FuncObject> {
public:
  ConstFunc(ValueType value) : Constant(ConstantType::Function), Value(value) {}

  void dump() const override;
};

} // namespace haneul