#include "libcaesar.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Caesar shift of 0 returns same", "[caesar]") {
  REQUIRE(caesar_shift(0, "Hello World!") == "Hello World!");
}
