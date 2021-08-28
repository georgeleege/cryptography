#include "substitution.h"
#include <catch2/catch_test_macros.hpp>

// went with making the empty key just return the input

// another possiblity that has good semantic meaning is
// 2a mod n where a is the input character and n is the size of the alphanet
// for odd n this works well on the encrypt where a <= n/2 map to even
// characters and a > n/2 map to odd characters for decryption even chars are
// simply divided by 2 and odd characters +n then divided by 2 for even n, the
// encryption of a >= n/2 would have to be handled to map to the odd numbers
// through a +1 the decryption would also require special handling of odd
// numbers as well

// decided against this for simplicity and because to eventually use templates
// to create arbitrary alphabets which may be even in size

TEST_CASE("Autokey encrypt with empty key returns same", "[autokey]") {
  REQUIRE(autokey_encrypt("", "Hello World!") == "Hello World!");
}

TEST_CASE("Autokey decrypt with empty key returns same", "[autokey]") {
  REQUIRE(autokey_decrypt("", "Hello World!") == "Hello World!");
}

TEST_CASE("Autokey encrypt with key ' ' of '     '", "[autokey]") {
  REQUIRE(autokey_encrypt(" ", "     ") == "     ");
}

TEST_CASE("Autokey decrypt with key ' ' of '     '", "[autokey]") {
  REQUIRE(autokey_decrypt(" ", "     ") == "     ");
}

TEST_CASE("Autokey encrypt with key '   '", "[autokey]") {
  REQUIRE(autokey_encrypt("   ", "!\"#~}|") == "!\"#   ");
}

TEST_CASE("Autokey decrypt with key '   '", "[autokey]") {
  REQUIRE(autokey_decrypt("   ", "!\"#   ") == "!\"#~}|");
}

TEST_CASE("Autokey encrypt with equal length key", "[autokey]") {
  REQUIRE(autokey_encrypt("!!!!!!!!!!!!", "Hello World!") == "Ifmmp!Xpsme\"");
}

TEST_CASE("Autokey decrypt with equal length key", "[autokey]") {
  REQUIRE(autokey_decrypt("!!!!!!!!!!!!", "Ifmmp!Xpsme\"") == "Hello World!");
}

TEST_CASE("Autokey encrypt with equal length key 2", "[autokey]") {
  REQUIRE(autokey_encrypt(" ! ! ! ! ! !", "Hello World!") == "Hflmo!Wprmd\"");
}

TEST_CASE("Autokey decrypt with equal length key 2", "[autokey]") {
  REQUIRE(autokey_decrypt(" ! ! ! ! ! !", "Hflmo!Wprmd\"") == "Hello World!");
}

TEST_CASE("Autokey encrypt with longer key", "[autokey]") {
  REQUIRE(autokey_encrypt(" ! ! ! ! ! !qeiobnakd", "Hello World!") ==
          "Hflmo!Wprmd\"");
}

TEST_CASE("Autokey decrypt with longer key 2", "[autokey]") {
  REQUIRE(autokey_decrypt(" ! ! ! ! ! !132bjkaf", "Hflmo!Wprmd\"") ==
          "Hello World!");
}
