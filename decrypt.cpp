#include <iostream>
#include <string>
#include "decrypt.h"
#include "caesar.h"
#include "vigenere.h"
// include encryption headers as we can reuse their functions instead of making convoluted solutions

// invert lowercase letter (a becomes z, b becomes y, etc.)
char invertLetter(char letter) {
    int letterRel = letter - 97; //subtract 97 since the first loweralpha char is id 97
    int newLetterRel = 26 - letterRel; //subtract from 26 to invert
    
    while (!(0 <= newLetterRel && newLetterRel <= 25)) {
        newLetterRel = (newLetterRel < 0) ? newLetterRel + 26 : newLetterRel - 26;
    }
    
    return newLetterRel + 97; //bring it back to lowercase alphas
}

// invert whole keyword
std::string invertKeyword(std::string keyword) {
    std::string newKeyword = "";
    
    for (int i = 0; i < keyword.length(); i++) {
        newKeyword = newKeyword + invertLetter(keyword[i]);
    }
    
    return newKeyword;
}

// instead of decrypting, we can reencrypt but in a way that cancels out the original encryption
// in this case, we just subtract the original shift from 26
std::string decryptCaesar(std::string ciphertext, int rshift) {
    return encryptCaesar(ciphertext, (26 - standardShift(rshift)));
}

// instead of decrypting, we can reencrypt but in a way that cancels out the original encryption
// in this case, we get a keyword with inverse chars of the key (a becomes z, b becomes y, etc.)
std::string decryptVigenere(std::string ciphertext, std::string keyword) {
    return encryptVigenere(ciphertext, invertKeyword(keyword));
}