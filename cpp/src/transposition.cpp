#include "transposition.h"
#include <string>
#include <string_view>

std::string transpose_col_encrypt(int width, std::string_view plaintext) {
  // need to handle negative widths
  if (width == 0 || width == 1 || width >= plaintext.size()) {
    return std::string{plaintext};
  }
  std::string output(plaintext.size(), ' ');
  int pos = 0;
  for (auto i = 0; i < width; ++i) {
    for (auto j = i; j < plaintext.size(); j += width) {
      output[pos] = plaintext[j];
      ++pos;
    }
  }
  return output;
}

std::string transpose_col_decrypt(int width, std::string_view ciphertext) {
  // need to handle negative widths
  if (width == 0 || width == 1 || width >= ciphertext.size()) {
    return std::string{ciphertext};
  }
  int decrypt_width = ciphertext.size() / width;
  int rem = ciphertext.size() % width;
  std::string output(ciphertext.size(), ' ');
  int pos = 0;
  for (auto i = 0; i < decrypt_width; ++i) {
    auto rem_cols = rem;
    for (auto j = i; j < ciphertext.size(); j += decrypt_width) {
      output[pos] = ciphertext[j];
      j = rem_cols > 0 ? j + 1 : j;
      --rem_cols;
      ++pos;
    }
  }
  for (auto i = 0, j = decrypt_width; i < rem; ++i, j += decrypt_width + 1) {
    output[pos] = ciphertext[j];
    ++pos;
  }
  return output;
}
