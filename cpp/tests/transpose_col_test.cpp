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

// easy case first where s.size() % width == 0
// nice that "Hello World!" is size 12 which divides 2,3,4,6 nicely

TEST_CASE("Transpose col encrypt with width 2", "[transpose_col]") {
  REQUIRE(transpose_col_encrypt(2, "Hello World!") == "HloWrdel ol!");
}

TEST_CASE("Transpose col decrypt with width 2", "[transpose_col]") {
  REQUIRE(transpose_col_decrypt(2, "HloWrdel ol!") == "Hello World!");
}

TEST_CASE("Transpose col encrypt with width 3", "[transpose_col]") {
  REQUIRE(transpose_col_encrypt(3, "Hello World!") == "HlWleoodl r!");
}

TEST_CASE("Transpose col decrypt with width 3", "[transpose_col]") {
  REQUIRE(transpose_col_decrypt(3, "HlWleoodl r!") == "Hello World!");
}

TEST_CASE("Transpose col encrypt with width 4", "[transpose_col]") {
  REQUIRE(transpose_col_encrypt(4, "Hello World!") == "Hore llWdlo!");
}

TEST_CASE("Transpose col decrypt with width 4", "[transpose_col]") {
  REQUIRE(transpose_col_decrypt(4, "Hore llWdlo!") == "Hello World!");
}

TEST_CASE("Transpose col encrypt with width 6", "[transpose_col]") {
  REQUIRE(transpose_col_encrypt(6, "Hello World!") == "HWeolrllod !");
}

TEST_CASE("Transpose col decrypt with width 6", "[transpose_col]") {
  REQUIRE(transpose_col_decrypt(6, "HWeolrllod !") == "Hello World!");
}


// when s.size() % width != 0, we have to make some decisions
// do we reject the input?
// pad the input?
// or account for unequal column sizes
