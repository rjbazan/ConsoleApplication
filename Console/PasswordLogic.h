#ifndef PASSWORD_LOGIC_H
#define PASSWORD_LOGIC_H

#include <string>

class PasswordLogic {
public:
    // Constructor
    PasswordLogic();

    // Method to generate a secure random password
    std::string generatePassword(int length) const;

private:
    const std::string uppercase;
    const std::string lowercase;
    const std::string digits;
    const std::string special;

    // Helper function to get a random character from a given pool
    char getRandomChar(const std::string& pool) const;
};

#endif // PASSWORD_LOGIC_H
