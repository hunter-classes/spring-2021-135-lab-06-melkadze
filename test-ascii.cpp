#include <iostream>

std::string asciiCodes(std::string s) {
    std::string result = "";
    
    for (int i = 0; i < s.length(); i++)
        result = result + s[i] + " " + std::to_string((int)s[i]) + "\n";
    
    return result;
}

void sampleAsciiCodes(std::string s) {
    std::cout << "---------- Sampling string '" << s << "' ----------\n" << asciiCodes(s);
}

int main() {
    sampleAsciiCodes("Cat :3 Dog");
    sampleAsciiCodes("Sample input.");
    sampleAsciiCodes("Aa Bb Cc");
    sampleAsciiCodes("!@#$%^&*()_+-=");
    return 0;
}