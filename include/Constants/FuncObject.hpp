#pragma once
#include <string>
#include <vector>

#include "Constant.hpp"
#include "Dumpable.hpp"
#include "Instruction.hpp"

namespace haneul {

class FuncObject : public Dumpable {
private:
  std::vector<std::string> arg_names_;
  Code code_;
  ConstantList const_table_;

public:
  const std::vector<std::string> &arg_names;
  const Code &code;
  const ConstantList &const_table;

  FuncObject(std::vector<std::string> arg_names, Code code,
             const ConstantList &const_table)
      : arg_names_(arg_names), code_(code), const_table_(const_table),
        arg_names(arg_names_), code(code_), const_table(const_table_) {}

  void dump() const override;
};

} // namespace haneul