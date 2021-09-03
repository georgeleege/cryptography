#include "transposition.h"
#include <string>

std::string transpose_col_encrypt(int width, std::string plaintext) {
  // need to handle negative widths
  if (width == 0 || width == 1 || width >= plaintext.size()) {
    return plaintext;
  }
  std::string output = "";
  for (auto i = 0; i < width; ++i) {
    for (auto j = i; j < plaintext.size(); j += width) {
      output += plaintext[j];
    }
  }
  return output;

}

std::string transpose_col_decrypt(int width, std::string ciphertext) {
  // need to handle negative widths
  if (width == 0 || width == 1 || width >= ciphertext.size()) {
    return ciphertext;
  }
  int decrypt_width = ciphertext.size() / width;
  return transpose_col_encrypt(decrypt_width, ciphertext);
}
