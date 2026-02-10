#include <iostream>
#include "generator.h"

int main() {
    Password password;

    int length;
    char upper, lower;
    char numbers, letters, symbols;
    
    std::cout << "Password length (minimum 5): ";
    std::cin >> length;

    // prevent invalid length
    if (!password.checkLength(length)) {
        std::cout << "Enter a length greather than 4 and less than 51." << std::endl;
        return 0;
    }

    std::cout << std::endl;

    password.setLength(length);

    // calls password generator
    std::string pass = password.generate();
    std::cout << pass << std::endl;
}