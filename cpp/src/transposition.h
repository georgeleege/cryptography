#ifndef TRANSPOSITION_H
#define TRANSPOSITION_H

#include <string>

std::string transpose_col_encrypt(int width, std::string plaintext);
std::string transpose_col_decrypt(int width, std::string ciphertext);

#endif
