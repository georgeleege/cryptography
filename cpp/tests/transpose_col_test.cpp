#include "transposition.h"
#include <catch2/catch_test_macros.hpp>

// width zero doesn't have any meaning, we will just make it return the same

TEST_CASE("Transpose col encrypt with width 0 returns same", "[transpose_col]") {
  REQUIRE(transpose_col_encrypt(0, "Hello World!") == "Hello World!");
}

TEST_CASE("Transpose col decrypt with width 0 returns same", "[transpose_col]") {
  REQUIRE(transpose_col_decrypt(0, "Hello World!") == "Hello World!");
}

TEST_CASE("Transpose col encrypt with width 1 returns same", "[transpose_col]") {
  REQUIRE(transpose_col_encrypt(1, "Hello World!") == "Hello World!");
}

TEST_CASE("Transpose col decrypt with width 1 returns same", "[transpose_col]") {
  REQUIRE(transpose_col_decrypt(1, "Hello World!") == "Hello World!");
}

TEST_CASE("Transpose col encrypt with same width returns same", "[transpose_col]") {
  std::string s = "Hello World!";
  REQUIRE(transpose_col_encrypt(s.size(), s) == "Hello World!");
}

TEST_CASE("Transpose col decrypt with same width returns same", "[transpose_col]") {
  std::string s = "Hello World!";
  REQUIRE(transpose_col_decrypt(s.size(), s) == "Hello World!");
}

TEST_CASE("Transpose col encrypt with greater width returns same", "[transpose_col]") {
  std::string s = "Hello World!";
  REQUIRE(transpose_col_encrypt(s.size()+1, s) == "Hello World!");
}

TEST_CASE("Transpose col decrypt with greater width returns same", "[transpose_col]") {
  std::string s = "Hello World!";
  REQUIRE(transpose_col_decrypt(s.size()+1, s) == "Hello World!");
}
