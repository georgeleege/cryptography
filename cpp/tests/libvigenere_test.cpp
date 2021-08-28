#include "libvigenere.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Vigenere encrypt with empty key returns same", "[vigenere]") {
  REQUIRE(vigenere_encrypt("", "Hello World!") == "Hello World!");
}

TEST_CASE("Vigenere decrypt with emtpy key returns same", "[vigenere]") {
  REQUIRE(vigenere_decrypt("", "Hello World!") == "Hello World!");
}

TEST_CASE("Vigenere encrypt with key ' ' returns same", "[vigenere]") {
  REQUIRE(vigenere_encrypt(" ", "Hello World!") == "Hello World!");
}

TEST_CASE("Vigenere decrypt with key ' ' returns same", "[vigenere]") {
  REQUIRE(vigenere_decrypt(" ", "Hello World!") == "Hello World!");
}

TEST_CASE("Vigenere encrypt with key '!'", "[vigenere]") {
  REQUIRE(vigenere_encrypt("!", "Hello World!") == "Ifmmp!Xpsme\"");
}

TEST_CASE("Vigenere decrypt with key '!'", "[vigenere]") {
  REQUIRE(vigenere_decrypt("!", "Ifmmp!Xpsme\"") == "Hello World!");
}

TEST_CASE("Vigenere encrypt with key ' !'", "[vigenere]") {
  REQUIRE(vigenere_encrypt(" !", "Hello World!") == "Hflmo!Wprmd\"");
}

TEST_CASE("Vigenere decrypt with key ' !'", "[vigenere]") {
  REQUIRE(vigenere_decrypt(" !", "Hflmo!Wprmd\"") == "Hello World!");
}

TEST_CASE("Vigenere encrypt with key longer than text", "[vigenere]") {
  REQUIRE(vigenere_encrypt(" ! ! ! ! ! ! ! ! !", "Hello World!") == "Hflmo!Wprmd\"");
}

TEST_CASE("Vigenere decrypt with key longer than text", "[vigenere]") {
  REQUIRE(vigenere_decrypt(" ! ! ! ! ! ! ! ! !", "Hflmo!Wprmd\"") == "Hello World!");
}

TEST_CASE("Vigenere encrypt with key that requires loop around", "[vigenere]") {
  REQUIRE(vigenere_encrypt("~~~", "Hello World!") == "Gdkkn~Vnqkc ");
}

TEST_CASE("Vigenere decrypt with key that requires loop around", "[vigenere]") {
  REQUIRE(vigenere_decrypt("~~~", "Gdkkn~Vnqkc ") == "Hello World!");
}
