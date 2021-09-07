#include "substitution.h"
#include <iostream>

#include "CLI/App.hpp"
#include "CLI/Config.hpp"
#include "CLI/Formatter.hpp"

int main(int argc, char **argv) {
  CLI::App app{"App description"};

  std::string filename = "default";
  app.add_option("-f,--file", filename, "A help string");

  CLI11_PARSE(app, argc, argv);
  return 0;
}
