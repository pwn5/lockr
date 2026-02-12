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

bool Password::setLength(int length) {
    // prevent invalid length
    if (!checkLength(length)) {
        return false;
    }

    this->length = length;
    return true;
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