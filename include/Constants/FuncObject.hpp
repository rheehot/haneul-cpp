#pragma once
#include <string>
#include <vector>

#include "Constant.hpp"
#include "Insturction.hpp"

namespace haneul {

class FuncObject {
private:
  std::vector<std::string> arg_names_;
  Code code_;
  std::vector<ConstantPtr> const_table_;

public:
  FuncObject(std::vector<std::string> arg_names, Code code,
             std::vector<ConstantPtr> const_table)
      : arg_names_(arg_names), code_(code),
        const_table_(std::move(const_table)) {}

  FuncObject(FuncObject &&) = default;
  FuncObject(const FuncObject &) = delete;
  FuncObject &operator=(const FuncObject &) = delete;
};

} // namespace haneul