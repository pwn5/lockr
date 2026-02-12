#include <iostream>
#include <random>
#include <chrono>
#include <cctype>
#include "generator.h"

Password::Password(int length, bool numbers, bool letters, 
    bool symbols, bool uppercase, bool lowercase, std::string password) 
    : length(length), numbers(numbers), symbols(symbols), uppercase(uppercase), lowercase(lowercase), password(password) {};

bool Password::checkLength(int length) {
    // don't allows password length < 4 and > 51
    return length > 4 && length < 51;
}

void Password::setLength(int length) {
    // prevent invalid length
    if (!checkLength(length)) {
        std::cout << "Enter a length greather than 4 and less than 51.";
        std::cout << std::endl;
        exit(0);
    }

    this->length = length;
}

std::string Password::addRange(char start, char end) {
    std::string characters = "";
    for (char c = start; c <= end; c++) {
        if (lowercase && start == 'A') 
            // generates lowercase too
            characters += tolower(c);
        characters += c;
    }

    return characters;
}

std::string Password::generate() {
    password.clear();
    std::string components = ""; // inicialize components

    // building components for the pasword
    components += addRange('0', '9');
    components += addRange('!', ')');
    components += addRange('A', 'Z');

    // seed with current time
    std::srand(std::time(0));

    for (int i = 0; i<(this->length); i++) {
        password += components[std::rand() % components.length()];
    }

    return password;
}