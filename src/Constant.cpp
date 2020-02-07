#include "Constant.hpp"

namespace haneul {
std::string type_to_string(const ConstantType &type) {
  switch (type) {
  case ConstantType::None:
    return "없음";
  case ConstantType::Integer:
    return "정수";
  }
} // namespace haneul
} // namespace haneul