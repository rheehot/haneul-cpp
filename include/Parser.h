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

  template <class T> T peek(std::size_t n = sizeof(T));
  template <class T> T consume(std::size_t n = sizeof(T));

  int64_t parse_integer();
  double parse_double();
  std::string parse_char();
  std::string parse_string();
}; // namespace haneul
} // namespace haneul