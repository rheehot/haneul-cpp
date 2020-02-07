#pragma once
#include <memory>
#include <string>

namespace haneul {
enum class ConstantType { None, Integer };

std::string type_to_string(ConstantType type);

class Constant {
private:
  using ConstantPtr = std::unique_ptr<Constant>;

public:
  virtual ConstantPtr add(ConstantPtr other) = 0;
  virtual ConstantPtr subtract(ConstantPtr other) = 0;
  virtual ConstantPtr multiply(ConstantPtr other) = 0;
  virtual ConstantPtr divide(ConstantPtr other) = 0;
  virtual ConstantPtr mod(ConstantPtr other) = 0;
  virtual ConstantPtr equal(ConstantPtr other) = 0;
  virtual ConstantPtr less_than(ConstantPtr other) = 0;
  virtual ConstantPtr greater_than(ConstantPtr other) = 0;

  virtual ConstantPtr negate() = 0;
  virtual std::string show() = 0;
};
} // namespace haneul