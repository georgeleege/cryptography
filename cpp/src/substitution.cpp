#include "substitution.h"
#include <string>
#include <string_view>

char shift(int key, char in) {
  if (in < ' ' || in > '~') {
    return in;
  }
  in -= ' ';
  // modulo with different signs is not standard
  return (95 + (in + key) % 95) % 95 + ' ';
}

char shift_char(signed char key, char in) {
  int int_key = key >= 0 ? key - ' ' : key + ' ';
  return shift(int_key, in);
}

std::string caesar_shift(int key, std::string_view text) {
  std::string output(text.size(), ' ');
  for (auto i = 0; i < text.size(); ++i) {
    output[i] = shift(key, text[i]);
  }
  return output;
}

std::string vigenere_encrypt(std::string_view key, std::string_view plaintext) {
  if (key.size() == 0) {
    return std::string{plaintext};
  }
  std::string output(plaintext.size(), ' ');
  auto key_pos = 0;
  for (auto i = 0; i < plaintext.size(); ++i) {
    output[i] = shift_char(key[key_pos], plaintext[i]);
    ++key_pos;
    key_pos %= key.size();
  }
  return output;
}

std::string vigenere_decrypt(std::string_view key,
                             std::string_view ciphertext) {
  if (key.size() == 0) {
    return std::string{ciphertext};
  }
  std::string output(ciphertext.size(), ' ');
  auto key_pos = 0;
  for (auto i = 0; i < ciphertext.size(); ++i) {
    output[i] = shift_char(-key[key_pos], ciphertext[i]);
    ++key_pos;
    key_pos %= key.size();
  }
  return output;
}

std::string autokey_encrypt(std::string_view key, std::string_view plaintext) {
  if (key.size() == 0) {
    return std::string{plaintext};
  }
  int ks = key.size();
  int ps = plaintext.size();
  std::string autokey(ps, ' ');
  for (auto i = 0; i < ks && i < ps; ++i) {
    autokey[i] = key[i];
  }
  for (auto i = ks, j = 0; i < ps; ++i, ++j) {
    autokey[i] = plaintext[j];
  }
  return vigenere_encrypt(autokey, plaintext);
}

std::string autokey_decrypt(std::string_view key, std::string_view ciphertext) {
  if (key.size() == 0) {
    return std::string{ciphertext};
  }

  // can do the following recursively, but maybe not great for small keys
  std::string output(ciphertext.size(), ' ');

  auto c_pos = 0;
  for (auto i = 0; i < key.size() && i < ciphertext.size(); ++i) {
    output[i] = shift_char(-key[i], ciphertext[i]);
    ++c_pos;
  }
  while (c_pos < ciphertext.size()) {
    int key_pos = c_pos - key.size();
    output[c_pos] = shift_char(-output[key_pos], ciphertext[c_pos]);
    ++c_pos;
  }
  return output;
}
