#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"

TEST_CASE("[B: shiftChar] Lowercase") {
    CHECK(shiftChar('a', 4) == 'e');
    CHECK(shiftChar('e', 10) == 'o');
    CHECK(shiftChar('o', 26) == 'o');
    CHECK(shiftChar('o', 12) == 'a');
    CHECK(shiftChar('a', 53) == 'b');
    CHECK(shiftChar('b', -1) == 'a');
    CHECK(shiftChar('a', -53) == 'z');
}

TEST_CASE("[B: shiftChar] Uppercase") {
    CHECK(shiftChar('A', 4) == 'E');
    CHECK(shiftChar('E', 10) == 'O');
    CHECK(shiftChar('O', 26) == 'O');
    CHECK(shiftChar('O', 12) == 'A');
    CHECK(shiftChar('A', 53) == 'B');
    CHECK(shiftChar('B', -1) == 'A');
    CHECK(shiftChar('A', -53) == 'Z');
}