#include <iostream>

#include "Constants/ConstInteger.hpp"
#include "Parser.hpp"

int main(int argc, char **argv) {
  if (argc <= 1) {
    std::cerr << "인수를 입력해주세요!" << std::endl;
    return EXIT_FAILURE;
  }

  haneul::Parser parser(argv[1]);
  auto [const_table, code] = parser.parse_program();

  for (const auto &c : const_table) {
    c->dump();
  }

  for (const auto &inst : code) {
    inst.dump();
  }

  // std::cout << result.show() << std::endl;
  // std::cout << parser.par() << '\n';
  return 0;
}