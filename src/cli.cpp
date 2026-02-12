#include <iostream>
#include <string>
#include "generator.h"
#include "cli.h"


Cli::Cli(std::string VERSION) : VERSION(VERSION) {};

void Cli::showVersion() {
    std::cout << "lockr version " << VERSION << std::endl;
    exit(0);
}

void Cli::handleGeneratePassword(int argc, char *argv[]) {
    Password password;

    for (int i = 3; i < argc; i++) {
        std::string arg = argv[i];

        if (arg == "-l" || arg == "--length") {

            if (i + 1 < argc) {
                password.setLength(std::stoi(argv[++i]));
                ++i; // jumps the value
            } else {
                std::cout << "Missing value for length.\n";
                exit(0);
            }
        }

        else {
            std::cout << "Unknown option: " << arg << "\n";
            exit(0);
        }
    }

    // calls password generator
    std::string pass = password.generate();
    std::cout << pass << "\n";
}

void Cli::processArguments(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cout << "You don't give any arguments." << "\n";
        exit(0);
    }

    // gets the command value
    std::string command = argv[1];

    if (command == "generate") {

        if (argc <= 2) {
            std::cout << "No subcommand provided.\n";
            exit(0);
        }

        // gets the subcommand value
        std::string subcommand = argv[2];

        if (subcommand == "password") {
            handleGeneratePassword(argc, argv);
        }
        else {
            std::cout << "Unknown generate subcommand.\n";
            exit(0);
        }
    }

    else {
        std::cout << "Unknown command.\n";
        exit(0);
    }
}