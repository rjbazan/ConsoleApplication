// Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PasswordLogic.h"

int main()
{
    std::cout << "Hello World!\n";
    PasswordLogic passwordLogic;

    int length;
    std::cout << "Enter the desired password length: ";
    std::cin >> length;

    try {
        std::string password = passwordLogic.generatePassword(length);
        std::cout << "Generated Password: " << password << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
