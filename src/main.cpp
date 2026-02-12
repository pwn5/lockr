#include <iostream>
#include "generator.h"
#include "cli.h"

int main(int argc, char *argv[]) {
    Cli cli;

    cli.processArguments(argc, argv);
}