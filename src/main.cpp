#include <iostream>

#include "Constants/ConstFunc.hpp"
#include "Constants/ConstInteger.hpp"
#include "Constants/ConstNone.hpp"
#include "Constants/NativeFunc.hpp"
#include "Interpreter.hpp"
#include "Parser.hpp"

int main(int argc, char **argv) {
  if (argc <= 1) {
    std::cerr << "인수를 입력해주세요!" << std::endl;
    return EXIT_FAILURE;
  }

  haneul::Parser parser(argv[1]);
  auto [const_table, code] = parser.parse_program();

  // for (const auto &c : const_table) {
  //   c->dump();
  // }

  // for (const auto &inst : code) {
  //   inst.dump();
  // }

  haneul::NativeFunc::FuncType print_func =
      [](auto args) -> haneul::ConstantPtr {
    args[0]->dump();
    return std::make_shared<haneul::ConstNone>();
  };

  auto print_func_object =
      std::make_shared<haneul::ConstFunc>(1, haneul::NativeFunc(print_func));
  haneul::Interpreter interp({{"보여주다", print_func_object}});

  interp.run({const_table, code.cbegin(), code.cend(), 0});
  return 0;
}