#include <bitset>
#include <cmath>
#include <fstream>
#include <iostream>

#include "Parser.h"

namespace haneul {
Parser::Parser(const std::string &input_file) {
  std::ifstream stream(input_file, std::ios::in | std::ios::binary);
  Parser::InputType content((std::istreambuf_iterator<char>(stream)),
                            std::istreambuf_iterator<char>());

  this->input_ = content;
}

template <class T> T Parser::consume() {
  T result = 0;
  const std::size_t result_size = sizeof(T);

  for (int i = 0; i < result_size; i++) {
    result += static_cast<T>(this->input_[this->pos_++])
              << (8 * (result_size - i - 1));
  }

  return result;
}

template <> uint8_t Parser::consume<uint8_t>() {
  return this->input_[this->pos_++];
}

template <> int8_t Parser::consume<int8_t>() {
  return this->input_[this->pos_++];
}

double Parser::parse_double() {
  auto base = this->consume<int64_t>();
  auto exp = this->consume<int64_t>();

  return base * std::pow(2, exp);
}

} // namespace haneul