#include <iostream>

#include "Parser.h"

int main() {
  haneul::Parser::InputType input = {2, 0, 0, 0, 0, 0, 0, 0, 3, 119, 111, 119};
  haneul::Parser parser(input);
  // parser.parse_instruction();
  std::cout << parser.parse_string() << '\n';
  return 0;
}