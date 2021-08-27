#include "libcaesar.h"
#include <string>

std::string caesar_shift(int key, std::string text) {
  std::string output = "";
  key %= 95;
  for (auto i = 0; i < text.size(); ++i) {
    char shifted = (text[i] - ' ' + key) % 95 + ' ';
    output += shifted;
  }
  return output;
}
