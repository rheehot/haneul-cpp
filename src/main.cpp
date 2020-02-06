#include <iostream>

#include "Parser.h"

int main() {
  haneul::Parser::InputType input = {
      0,   0,   0,   0,   0,   0,   0,   15,  236, 149, 136, 235, 133, 149, 237,
      149, 152, 236, 132, 184, 236, 154, 148, 32,  236, 132, 156, 235, 143, 153,
      237, 156, 152, 236, 158, 133, 235, 139, 136, 235, 139, 164, 32,  33,  33};
  haneul::Parser parser(input);
  std::cout << parser.parse_string() << '\n';
  return 0;
}