#include "libvigenere.h"
#include <string>

std::string vigenere_encrypt(std::string key, std::string plaintext) {
  if (key.size() == 0) {
    return plaintext;
  }
  std::string output = "";
  auto key_pos = 0;
  for (auto i = 0; i < plaintext.size(); ++i) {
    char p = plaintext[i] - ' ';
    char k = key[key_pos] - ' ';
    char shifted = (p + k) % 95 + ' ';
    ++key_pos;
    key_pos %= key.size();
    output += shifted;
  }
  return output;
}

std::string vigenere_decrypt(std::string key, std::string ciphertext) {
  if (key.size() == 0) {
    return ciphertext;
  }
  std::string output = "";
  auto key_pos = 0;
  for (auto i = 0; i < ciphertext.size(); ++i) {
    char c = ciphertext[i] - ' ';
    char k = key[key_pos] - ' ';
    // modulo with different signs is not standardized
    char shifted = (95 + (c - k)) % 95 + ' ';
    ++key_pos;
    key_pos %= key.size();
    output += shifted;
  }
  return output;
}
