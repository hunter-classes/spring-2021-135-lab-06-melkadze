#include <iostream>
#include "vigenere.h"
#include "caesar.h" //allows us to reuse shiftChar rather than making an identical function here

// returns if the given char is an alpha
bool isAlpha(char c) {
    return ((65 <= c && c <= 90) || (97 <= c && c <= 122));
}

// encrypts by vigenere
std::string encryptVigenere(std::string plaintext, std::string keyword) {
    std::string encoded = "";
    
    for (int i = 0; i < plaintext.length(); i++) {
        encoded = encoded + shiftChar(plaintext[i], rshift);
    }
    
    return encoded;
}