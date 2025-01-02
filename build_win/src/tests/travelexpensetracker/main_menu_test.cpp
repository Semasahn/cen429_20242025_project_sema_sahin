
/*  
#include <gtest/gtest.h>
#include "main_menu.h"
#include <sqlite3.h>
#include <filesystem>
#include <fstream>

class RegisterUserTest : public ::testing::Test {
protected:
    const std::string test_db_name = "test_expense_tracker.db";

    void SetUp() override {
        // Remove any existing test database
        std::remove(test_db_name.c_str());
    }

    void TearDown() override {
        // Clean up test database after each test
        std::remove(test_db_name.c_str());
    }

    bool doesUserExist(const std::string& username, const std::string& password) {
        sqlite3* db;
        sqlite3_open(test_db_name.c_str(), &db);

        std::string query = "SELECT COUNT(*) FROM users WHERE username = '" + username + "' AND password = '" + password + "';";
        sqlite3_stmt* stmt;
        int result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
        int user_count = 0;

        if (result == SQLITE_OK) {
            if (sqlite3_step(stmt) == SQLITE_ROW) {
                user_count = sqlite3_column_int(stmt, 0);
            }
        }

        sqlite3_finalize(stmt);
        sqlite3_close(db);

        return user_count > 0;
    }
};

TEST_F(RegisterUserTest, RegisterUserSuccess) {
    // Simulate user registration
    MainMenu menu;
    std::ofstream input("input.txt");
    input << "testuser\npassword123\n"; // Simulated input
    input.close();

    std::ifstream input_stream("input.txt");
    std::cin.rdbuf(input_stream.rdbuf()); // Redirect cin to use the simulated input

    // Call the method
    menu.registerUser();

    // Validate that the user is in the database
    EXPECT_TRUE(doesUserExist("testuser", "password123"));

    // Clean up
    input_stream.close();
    std::remove("input.txt");
}

TEST_F(RegisterUserTest, RegisterUserTableCreationFailure) {
    // Simulate failure to create the table by creating an invalid table beforehand
    sqlite3* db;
    sqlite3_open(test_db_name.c_str(), &db);
    std::string create_invalid_table = "CREATE TABLE users (id INTEGER PRIMARY KEY);";
    sqlite3_exec(db, create_invalid_table.c_str(), nullptr, nullptr, nullptr);
    sqlite3_close(db);

    MainMenu menu;
    std::ofstream input("input.txt");
    input << "testuser\npassword123\n"; // Simulated input
    input.close();

    std::ifstream input_stream("input.txt");
    std::cin.rdbuf(input_stream.rdbuf()); // Redirect cin to use the simulated input

    // Call the method
    menu.registerUser();

    // Validate that the user is NOT in the database
    EXPECT_FALSE(doesUserExist("testuser", "password123"));

    // Clean up
    input_stream.close();
    std::remove("input.txt");
}

// Additional tests can include cases like SQL injection attempts or empty input.
*/