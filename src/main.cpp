#include <iostream>

#include "Parser.hpp"

int main() {
  haneul::Parser::InputType input = {0, 0, 0, 5, 2, 0,   0,   0,
                                     0, 0, 0, 0, 3, 119, 111, 119};
  haneul::Parser parser(input);
  auto result = parser.parse_instruction();
  result.dump();
  // std::cout << parser.par() << '\n';
  return 0;
}