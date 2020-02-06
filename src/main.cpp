#include <iostream>

#include "Parser.h"

int main() {
  haneul::Parser::InputType input = {0,   21,  0,   0,   0,   0,   0,   0,
                                     255, 255, 255, 255, 255, 255, 255, 207};
  haneul::Parser parser(input);
  std::cout << parser.parse_double() << '\n';
  return 0;
}