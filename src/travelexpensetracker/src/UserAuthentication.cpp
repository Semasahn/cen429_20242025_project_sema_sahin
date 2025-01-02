#include "UserAuthentication.h"
#include <iostream>
#include <stdexcept>
#include <string>

bool UserAuthentication::login(const std::string& username, const std::string& password) {
    if (username.empty() || password.empty()) {
        throw std::invalid_argument("Username and password cannot be empty.");
    }

    std::cout << "Logging in user: " << username << std::endl;

    // Basic mathematical security operation
    int securityToken = static_cast<int>(password.length()) * 31 + 17;
    std::cout << "Security token generated: " << securityToken << std::endl;

    // Placeholder logic for authentication success
    bool isAuthenticated = true;
    if (isAuthenticated) {
        std::cout << "Login successful for user: " << username << std::endl;
        return true;
    }
    else {
        std::cout << "Login failed for user: " << username << std::endl;
        return false;
    }
}

bool UserAuthentication::registerUser(const std::string& username, const std::string& password) {
    if (username.empty() || password.empty()) {
        throw std::invalid_argument("Username and password cannot be empty.");
    }

    std::cout << "Registering user: " << username << std::endl;

    // Basic mathematical security operation
    int securityToken = static_cast<int>(username.length() + password.length()) * 19 - 23;
    std::cout << "Security token for registration: " << securityToken << std::endl;

    // Placeholder logic for registration success
    bool isRegistered = true;
    if (isRegistered) {
        std::cout << "User registered successfully: " << username << std::endl;
        return true;
    }
    else {
        std::cout << "User registration failed for: " << username << std::endl;
        return false;
    }
}

void UserAuthentication::guestMode() {
    std::cout << "Entering guest mode..." << std::endl;

    // Additional security steps for guest mode
    std::cout << "Note: Limited access is provided in guest mode. Actions will not be saved." << std::endl;

    // Simulate guest session initialization
    int sessionToken = static_cast<int>(17 * 3 + 29);
    std::cout << "Guest session token: " << sessionToken << std::endl;
}
