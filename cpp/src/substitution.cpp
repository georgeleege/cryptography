#include "substitution.h"
#include <string>

char shift(int key, char in) {
  in -= ' ';
  // modulo with different signs is not standard
  return (95 + (in + key) % 95) % 95 + ' ';
}

char shift_char(signed char key, char in) {
  int int_key = key >= 0 ? key - ' ' : key + ' ';
  return shift(int_key, in);
}

std::string caesar_shift(int key, std::string text) {
  std::string output = "";
  for (auto i = 0; i < text.size(); ++i) {
    output += shift(key, text[i]);
  }
  return output;
}

std::string vigenere_encrypt(std::string key, std::string plaintext) {
  if (key.size() == 0) {
    return plaintext;
  }
  std::string output = "";
  auto key_pos = 0;
  for (auto i = 0; i < plaintext.size(); ++i) {
    output += shift_char(key[key_pos], plaintext[i]);
    ++key_pos;
    key_pos %= key.size();
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
    output += shift_char(-key[key_pos], ciphertext[i]);
    ++key_pos;
    key_pos %= key.size();
  }
  return output;
}

std::string autokey_encrypt(std::string key, std::string plaintext) {
  if (key.size() == 0) {
    return plaintext;
  }
  auto autokey = key + plaintext;
  return vigenere_encrypt(autokey, plaintext);
}

std::string autokey_decrypt(std::string key, std::string ciphertext) {
  if (key.size() == 0) {
    return ciphertext;
  }

  // can do the following recursively, but maybe not great for small keys
  std::string output = "";

  auto c_pos = 0;
  for (auto i = 0; i < key.size() && i < ciphertext.size(); ++i) {
    output += shift_char(-key[i], ciphertext[i]);
    ++c_pos;
  }
  while (c_pos < ciphertext.size()) {
    int key_pos = c_pos - key.size();
    output += shift_char(-ciphertext[key_pos], ciphertext[c_pos]);
    ++c_pos;
  }
  return output;
}
