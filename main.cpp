#include <iostream>
#include <string>

#include "Database.hpp"

int main() {
    Database db;
    std::string input;

    std::cout<<"Welcome to In-memory-db! Type a command to proceed: \n";

    while (true) {
        std::getline(std::cin, input);
        if (input == "exit") break;
        db.executeCommand(input);
    }
    return 0;
}