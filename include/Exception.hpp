#pragma once
#include <cstdint>
#include <exception>
#include <string>

namespace haneul {
class HaneulException : public std::exception {
private:
  std::string msg_;
  uint32_t line_number_;

public:
  HaneulException(const std::string &msg, uint32_t line_number = 0) noexcept
      : msg_(msg), line_number_(line_number) {}
  virtual const char *what() const noexcept;

  uint32_t get_line_number() const noexcept;
};

class TypeException : public HaneulException {
  using HaneulException::HaneulException;
};

class InterpreterException : public HaneulException {
  using HaneulException::HaneulException;
};
} // namespace haneul