#include <variant>

#include "Constant.hpp"
#include "FuncObject.hpp"
#include "Instruction.hpp"
#include "NativeFunc.hpp"
#include "Value.hpp"

namespace haneul {

class ConstFunc : public Constant,
                  public Value<std::variant<FuncObject, NativeFunc>> {
private:
  uint8_t arity_;

public:
  ConstFunc(uint8_t arity, ValueType value)
      : Constant(ConstantType::Function), Value(value), arity_(arity) {}

  uint8_t arity() const noexcept { return arity_; }

  void dump() const override;
};

} // namespace haneul