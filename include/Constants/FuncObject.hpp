#pragma once
#include <string>
#include <vector>

#include "Constant.hpp"
#include "Dumpable.hpp"
#include "Instruction.hpp"

namespace haneul {

class FuncObject : public Dumpable {
private:
  uint8_t arity_;
  Code code_;
  ConstantList const_table_;

public:
  FuncObject(uint8_t arity, Code code, const ConstantList &const_table)
      : arity_(arity), code_(code), const_table_(const_table) {}

  const decltype(arity_) &arity() const { return arity_; }
  const decltype(code_) &code() const { return code_; }
  const decltype(const_table_) &const_table() const { return const_table_; }

  void dump() const override;
};

} // namespace haneul