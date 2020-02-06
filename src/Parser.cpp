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

template <class T> T Parser::peek(std::size_t n) {
  T result = 0;

  for (int i = 0; i < n; i++) {
    result += static_cast<T>(this->input_[this->pos_ + i]) << (8 * (n - i - 1));
  }

  return result;
}

template <class T> T Parser::consume(std::size_t n) {
  auto result = this->peek<T>(n);
  this->pos_ += sizeof(T);
  return result;
}

template <> uint8_t Parser::consume<uint8_t>(std::size_t) {
  return this->input_[this->pos_++];
}

template <> int8_t Parser::consume<int8_t>(std::size_t) {
  return this->input_[this->pos_++];
}

int64_t Parser::parse_integer() { return this->consume<int64_t>(); }

double Parser::parse_double() {
  auto base = this->consume<int64_t>();
  auto exp = this->consume<int64_t>();

  return base * std::pow(2, exp);
}

std::string Parser::parse_char() {
  auto head = this->peek<uint8_t>();
  std::size_t count = 0;

  if (head < 0x80) {
    count = 1;
  } else if (head < 0xE0) {
    count = 2;
  } else if (head < 0xF0) {
    count = 3;
  } else {
    count = 4;
  }

  std::string result = "";
  for (int i = 0; i < count; i++)
    result += this->consume<int8_t>();

  return result;
}

std::string Parser::parse_string() {
  auto count = this->consume<uint64_t>();

  std::string result = "";
  for (int i = 0; i < count; i++) {
    result += this->parse_char();
  }

  return result;
}
} // namespace haneul