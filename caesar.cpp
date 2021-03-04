#include <iostream>
#include "caesar.h"

// take any rshift value and convert it such that 0 <= rshift <= 25
int standardShift(int rshift) {
    int newShift = rshift;
    
    while (!(0 <= newShift && newShift <= 25)) {
        newShift = (newShift < 0) ? newShift + 26 : newShift - 26;
    }
    
    return newShift;
}

char shiftChar(char c, int rshift) {
    int newShift = standardShift(rshift);
    char newChar = c;
    
    if (65 <= c && c <= 90) {
        // capitals
        for (int i = newShift; i > 0; i--) {
            if (newChar == 90)
                newChar = 65;
            else
                newChar++;
        }
        
    } else if (97 <= c && c <= 122) {
        // lowercases
        for (int i = newShift; i > 0; i--) {
            if (newChar == 122)
                newChar = 97;
            else
                newChar++;
        }
    } //ignore all others (symbols)
    
    return newChar;
}

std::string encryptCaesar(std::string plaintext, int rshift) {
    std::string encoded = "";
    
    for (int i = 0; i < plaintext.length(); i++) {
        encoded = encoded + shiftChar(plaintext[i], rshift);
    }
    
    return encoded;
}