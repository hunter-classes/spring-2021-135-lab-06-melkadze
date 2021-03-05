#include <iostream>
#include <string>
#include "decrypt.h"
#include "caesar.h"
#include "vigenere.h"
// include encryption headers as we can reuse their functions instead of making convoluted solutions

// instead of decrypting, we can reencrypt but in a way that cancels out the original encryption
// in this case, we just subtract the original shift from 26
std::string decryptCaesar(std::string ciphertext, int rshift) {
    return encryptCaesar(ciphertext, (26 - standardShift(rshift)));
}

// instead of decrypting, we can reencrypt but in a way that cancels out the original encryption
// in this case, we get a keyword of with inverse chars (a becomes z, b becomes y, etc.)
std::string decryptVigenere(std::string ciphertext, std::string keyword) {
    return "e"; //temp, else compiler warn
}