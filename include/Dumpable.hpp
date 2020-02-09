#pragma once

namespace haneul {
class Dumpable {
public:
  virtual void dump() const = 0;
};
} // namespace haneul