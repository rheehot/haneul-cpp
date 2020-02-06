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

private:
  std::vector<uint8_t> input_;
  std::size_t pos_;
};
} // namespace haneul