#include <iostream>
#include "vigenere.h"
#include "caesar.h" //allows us to reuse shiftChar rather than making an identical function here

// returns if the given char is an alpha
bool isAlpha(char c) {
    return ((65 <= c && c <= 90) || (97 <= c && c <= 122));
}

// gets the proper shift from keyword string (supports overflow / loop-back)
char keywordShift(std::string keyword, int shift) {
    int newShift = shift;
    
    while (!(0 <= newShift && newShift <= keyword.length() - 1)) {
        newShift = (newShift < 0) ? newShift + keyword.length() : newShift - keyword.length();
    }
    
    return keyword[newShift] - 97; //subtract 97 since the first loweralpha char is id 97
}

// encrypts by vigenere
std::string encryptVigenere(std::string plaintext, std::string keyword) {
    std::string encoded = "";
    int keywordCounter = 0;
    
    for (int i = 0; i < plaintext.length(); i++) {
        encoded = encoded + shiftChar(plaintext[i], keywordShift(keyword, keywordCounter));
        
        if (isAlpha(plaintext[i]))
            keywordCounter++; //only advance if an alpha is used
    }
    
    return encoded;
}