#ifndef LIBVIGENERE_H
#define LIBVIGENERE_H

#include <string>

std::string vigenere_encrypt(std::string key, std::string plaintext);
std::string vigenere_decrypt(std::string key, std::string ciphertext);

#endif
