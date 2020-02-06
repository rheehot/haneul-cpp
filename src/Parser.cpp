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
} // namespace haneul