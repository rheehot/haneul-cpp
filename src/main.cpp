#include <iostream>

#include "Constants/ConstInteger.hpp"
#include "Parser.hpp"

int main() {
  haneul::Parser::InputType input = {3, 234, 176, 146};
  haneul::Parser parser(input);
  auto result = parser.parse_constant();

  result->dump();
  // std::cout << result.show() << std::endl;
  // std::cout << parser.par() << '\n';
  return 0;
}