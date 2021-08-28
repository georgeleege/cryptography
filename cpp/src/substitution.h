#ifndef SUBSTITUTION_H
#define SUBSTITUTION_H

#include <string>

std::string caesar_shift(int key, std::string text);

std::string vigenere_encrypt(std::string key, std::string plaintext);
std::string vigenere_decrypt(std::string key, std::string ciphertext);

#endif
