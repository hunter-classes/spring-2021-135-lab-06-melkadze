#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

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

TEST_CASE("[B: shiftChar] Non-alphabetic characters (should not shift)") {
    CHECK(shiftChar('^', 4) == '^');
    CHECK(shiftChar('#', 10) == '#');
    CHECK(shiftChar('@', 26) == '@');
    CHECK(shiftChar('4', 12) == '4');
    CHECK(shiftChar(' ', 53) == ' ');
    CHECK(shiftChar(';', -1) == ';');
    CHECK(shiftChar('"', -53) == '"');
}



TEST_CASE("[B: encryptCaesar] Shiftable strings") {
    CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
    CHECK(encryptCaesar("ABCD, abcd", 1) == "BCDE, bcde");
    CHECK(encryptCaesar("this is identical to", 26) == "this is identical to");
}

TEST_CASE("[B: encryptCaesar] Nonshiftable strings") {
    CHECK(encryptCaesar("!!!!!?????", 10) == "!!!!!?????");
    CHECK(encryptCaesar("1234, 5678", 1) == "1234, 5678");
    CHECK(encryptCaesar("     ", 5) == "     ");
}



TEST_CASE("[C: encryptVigenere] Shiftable strings") {
    CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
    CHECK(encryptVigenere("ATTACKATDAWN", "lemon") == "LXFOPVEFRNHR");
    CHECK(encryptVigenere("ABCD, abcd", "b") == "BCDE, bcde");
    CHECK(encryptVigenere("this is identical to", "a") == "this is identical to");
}

TEST_CASE("[C: encryptVigenere] Nonshiftable strings") {
    CHECK(encryptVigenere("!!!!!?????", "cake") == "!!!!!?????");
    CHECK(encryptVigenere("1234, 5678", "lemon") == "1234, 5678");
    CHECK(encryptVigenere("     ", "a") == "     ");
}



TEST_CASE("[D: decryptCaesar] Shiftable strings") {
    CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
    CHECK(decryptCaesar("BCDE, bcde", 1) == "ABCD, abcd");
    CHECK(decryptCaesar("this is identical to", 26) == "this is identical to");
}

TEST_CASE("[D: decryptCaesar] Nonshiftable strings") {
    CHECK(decryptCaesar("!!!!!?????", 10) == "!!!!!?????");
    CHECK(decryptCaesar("1234, 5678", 1) == "1234, 5678");
    CHECK(decryptCaesar("     ", 5) == "     ");
}



TEST_CASE("[D: decryptVigenere] Shiftable strings") {
    CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
    CHECK(decryptVigenere("LXFOPVEFRNHR", "lemon") == "ATTACKATDAWN");
    CHECK(decryptVigenere("BCDE, bcde", "b") == "ABCD, abcd");
    CHECK(decryptVigenere("this is identical to", "a") == "this is identical to");
}

TEST_CASE("[D: decryptVigenere] Nonshiftable strings") {
    CHECK(decryptVigenere("!!!!!?????", "cake") == "!!!!!?????");
    CHECK(decryptVigenere("1234, 5678", "lemon") == "1234, 5678");
    CHECK(decryptVigenere("     ", "a") == "     ");
}