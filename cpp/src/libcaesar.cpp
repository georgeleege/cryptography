#include "libcaesar.h"
#include <string>

std::string caesar_shift(int key, std::string text) {
  std::string output = "";
  // modulo with different signs is not standardized
  key = (95 + key % 95) % 95;
  for (auto i = 0; i < text.size(); ++i) {
    unsigned char shifted = (text[i] - ' ' + key) % 95 + ' ';
    output += shifted;
  }
  return output;
}
