#pragma once
#include <cstddef>
#include <cstdint>
#include <functional>
#include <string>
#include <vector>

#include "Constant.hpp"
#include "Constants/FuncObject.hpp"
#include "Insturction.hpp"

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
  char32_t parse_char();
  std::string parse_string();
  bool parse_boolean();
  FuncObject parse_func_object();

  Instruction parse_instruction();
  ConstantPtr parse_constant();

  std::pair<ConstantList, Code> parse_program();

  template <class Functor>
  std::vector<std::invoke_result_t<Functor>> parse_list(Functor &&parse_func);
};
} // namespace haneul