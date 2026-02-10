#include <iostream>

class Password {
private:
    int length;
    bool numbers, letters, symbols;
    bool uppercase, lowercase;
    std::string password;

    std::string addRange(char start, char end);
public:
    // constructor with optional params
    Password(int length = 8, bool numbers = true, bool letters = true,
             bool symbols = true, bool uppercase = true, bool lowercase = true, std::string password = "");

    // set new lengths
    void setLength(int length);

    bool checkLength(int length);
    std::string generate();
};