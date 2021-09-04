#ifndef TRANSPOSITION_H
#define TRANSPOSITION_H

#include <string>
#include <string_view>

std::string transpose_col_encrypt(int width, std::string_view plaintext);
std::string transpose_col_decrypt(int width, std::string_view ciphertext);

#endif
