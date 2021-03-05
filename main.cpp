#include <iostream>
#include <string>
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

void simulateProgram(std::string plaintext, std::string keyword, int rshift) {
  std::cout << "----------------------------------------------------------\n";
  std::cout << "Experimenting with plaintext '" << plaintext << "', keyword '" << keyword << "', and rshift " << rshift << ".\n";
  std::cout << "Shift first char of plaintext by rshift: " << shiftChar(plaintext[0], rshift) << "\n";
  std::cout << "Use Caesar encryption: " << encryptCaesar(plaintext, rshift) << "\n";
  std::cout << "Use Vigenere encryption: " << encryptVigenere(plaintext, keyword) << "\n";
  std::cout << "Use Caesar decryption: " << decryptCaesar(plaintext, rshift) << "\n";
  std::cout << "Use Vigenere decryption: " << decryptVigenere(plaintext, keyword) << "\n";
}

int main() {
  std::cout << "All tests are implemented in tests.cpp.\n";
  std::cout << "Please run 'make tests; ./tests -s' to view their results.\n";
  std::cout << "For now, we will run a few simulations of a real program here.\n";
  
  // run a few simulations
  simulateProgram("Hello, world!", "peach", 5);
  simulateProgram("Rovvy, Gybvn!", "lemon", 10);
  simulateProgram("Jevpq, Wyvnd!", "cake", 15);
  
  return 0;
}