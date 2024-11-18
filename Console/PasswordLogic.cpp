#include "PasswordLogic.h"
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <stdexcept>

// Constructor: Initialize character pools and seed RNG
PasswordLogic::PasswordLogic()
    : uppercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ"),
    lowercase("abcdefghijklmnopqrstuvwxyz"),
    digits("0123456789"),
    special("!@#$%^&*()-_=+[]{}|;:,.<>?/") {
    srand(static_cast<unsigned>(time(nullptr)));
}

// Helper function to get a random character from a given pool
char PasswordLogic::getRandomChar(const std::string& pool) const {
    return pool[rand() % pool.size()];
}

// Generate a secure random password
std::string PasswordLogic::generatePassword(int length) const {
    if (length < 4) {
        throw std::invalid_argument("Password length must be at least 4 to include all character types.");
    }

    // Ensure at least one character from each pool
    std::vector<char> password = {
        getRandomChar(uppercase),
        getRandomChar(lowercase),
        getRandomChar(digits),
        getRandomChar(special)
    };

    // Combine all character pools for the remaining characters
    std::string allChars = uppercase + lowercase + digits + special;

    // Randomly select remaining characters
    for (int i = 4; i < length; ++i) {
        password.push_back(getRandomChar(allChars));
    }

    // Shuffle the password to avoid predictable order
    std::shuffle(password.begin(), password.end(), std::mt19937(std::random_device()()));

    // Convert password vector to string
    return std::string(password.begin(), password.end());
}
