#include "libcaesar.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Caesar shift of 0 returns same", "[caesar]") {
  REQUIRE(caesar_shift(0, "Hello World!") == "Hello World!");
}

TEST_CASE("Caesar shift of 1", "[caesar]") {
  REQUIRE(caesar_shift(1, "Hello World!") == "Ifmmp!Xpsme\"");
}

TEST_CASE("Caesar shift of -1", "[caesar]") {
  REQUIRE(caesar_shift(-1, "Ifmmp!Xpsme\"") == "Hello World!");
}

// There are 95 printable ASCII characters
TEST_CASE("Caesar shift of 95", "[caesar]") {
  REQUIRE(caesar_shift(95, "Hello World!") == "Hello World!");
}

TEST_CASE("Caesar shift of 96", "[caesar]") {
  REQUIRE(caesar_shift(96, "Hello World!") == "Ifmmp!Xpsme\"");
}

TEST_CASE("Caesar shift of -96", "[caesar]") {
  REQUIRE(caesar_shift(-96, "Ifmmp!Xpsme\"") == "Hello World!");
}
