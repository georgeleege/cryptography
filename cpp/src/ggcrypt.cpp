#include "substitution.h"
#include <iostream>

#include "CLI/App.hpp"
#include "CLI/Config.hpp"
#include "CLI/Formatter.hpp"

int main(int argc, char **argv) {
  CLI::App app{"ggcrypt provides a set of cryptographic methods for toy use"};

  auto version = [](int count) { std::cout << "1.0.0" << '\n'; };
  app.add_flag("-v,--version", version, "Print the version number and exit");

  app.require_subcommand(/* min */ 0, /* max */ 1);

  CLI::App *caesar = app.add_subcommand("caesar", "Caesar Shift");
  bool encrypt;
  int caesar_key;
  std::string text;
  caesar->add_flag("-e,--encrypt,!-d,!--decrypt", encrypt, "Encrypt or decrypt")
      ->required();
  caesar->add_option("-k,--key", caesar_key, "Integer key")->required();
  caesar->add_option("text", text, "Text to encrypt or decrypt")->required();
  caesar->callback([&]() {
    if (!encrypt) {
      caesar_key *= -1;
    }
    std::cout << caesar_shift(caesar_key, text) << '\n';
  });

  CLI11_PARSE(app, argc, argv);
  return 0;
}
