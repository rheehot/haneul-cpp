#pragma once
#include <memory>

namespace haneul {
template <class T> class Value {
private:
  T value_;

public:
  Value(T v) : value_(std::move(v)), value(value_) {}

  const T &value;
  using ValueType = T;
};
} // namespace haneul