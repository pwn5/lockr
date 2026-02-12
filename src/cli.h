#include <iostream>

class Cli {
private:
    std::string VERSION;

public:
    int argc;
    char *argv[];

    Cli(std::string VERSION = "0.1.0");

    void handleGeneratePassword(int argc, char *argv[]);
    void processArguments(int argc, char *argv[]);
    void showVersion();
};