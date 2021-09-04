#ifndef SUBSTITUTION_H
#define SUBSTITUTION_H

#include <string>
#include <string_view>

char shift(int key, char in);
char shift_char(signed char key, char in);

std::string caesar_shift(int key, std::string_view text);

std::string vigenere_encrypt(std::string_view key, std::string_view plaintext);
std::string vigenere_decrypt(std::string_view key, std::string_view ciphertext);

std::string autokey_encrypt(std::string_view key, std::string_view plaintext);
std::string autokey_decrypt(std::string_view key, std::string_view ciphertext);

#endif
