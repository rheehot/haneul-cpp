#include <iostream>

#include "Parser.h"

int main() {
  haneul::Parser::InputType input = {0, 1};
  haneul::Parser parser(input);
  std::cout << parser.parse_boolean() << '\n';
  std::cout << parser.parse_boolean() << '\n';
  return 0;
}