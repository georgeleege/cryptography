#ifndef SUBSTITUTION_H
#define SUBSTITUTION_H

#include <string>

char shift(int key, char in);
char shift_char(signed char key, char in);

std::string caesar_shift(int key, std::string text);

std::string vigenere_encrypt(std::string key, std::string plaintext);
std::string vigenere_decrypt(std::string key, std::string ciphertext);

std::string autokey_encrypt(std::string key, std::string plaintext);
std::string autokey_decrypt(std::string key, std::string ciphertext);

#endif
