#include "substitution.h"
#include "transposition.h"
#include "primes.h"

#include <iostream>

#include "CLI/App.hpp"
#include "CLI/Config.hpp"
#include "CLI/Formatter.hpp"

int main(int argc, char **argv) {
  CLI::App app{"ggcrypt provides a set of cryptographic methods for toy use"};

  auto version = [](int count) { std::cout << "1.0.0" << '\n'; };
  app.add_flag("-v,--version", version, "Print the version number and exit");

  app.require_subcommand(/* min */ 0, /* max */ 1);

  bool encrypt;
  std::string text;
  std::string text_key;

  CLI::App *caesar = app.add_subcommand("caesar", "Caesar Shift");
  int caesar_key;
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

  CLI::App *vigenere = app.add_subcommand("vigenere", "Vigenere Cipher");
  vigenere
      ->add_flag("-e,--encrypt,!-d,!--decrypt", encrypt, "Encrypt or decrypt")
      ->required();
  vigenere->add_option("-k,--key", text_key, "String key")->required();
  vigenere->add_option("text", text, "Text to encrypt or decrypt")->required();
  vigenere->callback([&]() {
    if (encrypt) {
      std::cout << vigenere_encrypt(text_key, text) << '\n';
    } else {
      std::cout << vigenere_decrypt(text_key, text) << '\n';
    }
  });

  CLI::App *autokey = app.add_subcommand("autokey", "Autokey Cipher");
  autokey
      ->add_flag("-e,--encrypt,!-d,!--decrypt", encrypt, "Encrypt or decrypt")
      ->required();
  autokey->add_option("-k,--key", text_key, "String key")->required();
  autokey->add_option("text", text, "Text to encrypt or decrypt")->required();
  autokey->callback([&]() {
    if (encrypt) {
      std::cout << autokey_encrypt(text_key, text) << '\n';
    } else {
      std::cout << autokey_decrypt(text_key, text) << '\n';
    }
  });

  CLI11_PARSE(app, argc, argv);
  return 0;
}
