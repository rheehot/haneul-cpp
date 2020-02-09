#include <map>
#include <string>
#include <vector>

#include "Constant.hpp"
#include "Insturction.hpp"
#include "Value.hpp"

namespace haneul {

class FuncObject {
private:
  std::vector<std::string> arg_names_;
  Code code_;
  std::vector<Constant> const_table_;
};

class ConstFunc : public Constant, public Value<FuncObject> {
public:
  ConstFunc(ValueType value) : Constant(ConstantType::Function), Value(value) {}

  void dump() const override;
};

} // namespace haneul