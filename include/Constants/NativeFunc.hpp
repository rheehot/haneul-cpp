#pragma once
#include <functional>
#include <vector>

#include "Constant.hpp"
#include "Dumpable.hpp"

namespace haneul {
class NativeFunc {
public:
  using FuncType = std::function<ConstantPtr(std::vector<ConstantPtr>)>;

private:
  FuncType func_;

public:
  NativeFunc(const FuncType &func) : func_(func) {}

  const FuncType &func() const noexcept { return func_; }
};
} // namespace haneul