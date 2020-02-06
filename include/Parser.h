#pragma once
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace haneul {
class Parser {
public:
  using InputType = std::vector<uint8_t>;

  Parser(const std::string &input_file);
  Parser(const InputType &input) : input_(input) {}

public:
  std::vector<uint8_t> input_;
  std::size_t pos_ = 0;

  template <class T> T consume();

  int64_t parse_integer();
  double parse_double();
}; // namespace haneul
} // namespace haneul