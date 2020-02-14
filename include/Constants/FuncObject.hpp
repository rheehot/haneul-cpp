#pragma once
#include <string>
#include <vector>

#include "Constant.hpp"
#include "Dumpable.hpp"
#include "Instruction.hpp"

namespace haneul {

class FuncObject : public Dumpable {
private:
  Code code_;
  ConstantList const_table_;

public:
  FuncObject(Code code, const ConstantList &const_table)
      : code_(code), const_table_(const_table) {}

  const decltype(code_) &code() const { return code_; }
  const decltype(const_table_) &const_table() const { return const_table_; }

  void dump() const override;
};

} // namespace haneul