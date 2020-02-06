#include <iostream>

#include "Parser.h"

int main() {
  haneul::Parser::InputType input = {234, 176, 132};
  haneul::Parser parser(input);
  std::cout << parser.parse_char() << '\n';
  return 0;
}