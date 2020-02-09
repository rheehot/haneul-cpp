#include <iostream>

#include "Constants/ConstInteger.hpp"
#include "Parser.hpp"

int main() {
  haneul::Parser::InputType input = {
      5,   0,   0,   0,   0,   0,   0,   0,   2,   0,   0,   0,  0, 0, 0,
      0,   2,   236, 136, 152, 49,  0,   0,   0,   0,   0,   0,  0, 2, 236,
      136, 152, 50,  0,   0,   0,   0,   0,   0,   0,   3,   1,  0, 0, 0,
      0,   0,   0,   0,   10,  3,   234, 176, 129, 2,   0,   21, 0, 0, 0,
      0,   0,   0,   255, 255, 255, 255, 255, 255, 255, 207, 0,  0, 0, 0,
      0,   0,   0,   3,   0,   0,   0,   1,   3,   0,   0,   0,  0, 0, 0,
      0,   2,   236, 136, 152, 49,  0,   0,   0,   1,   3,   0,  0, 0, 0,
      0,   0,   0,   2,   236, 136, 152, 50,  0,   0,   0,   1,  8};
  haneul::Parser parser(input);
  auto result = parser.parse_constant();

  result->dump();
  // std::cout << result.show() << std::endl;
  // std::cout << parser.par() << '\n';
  return 0;
}