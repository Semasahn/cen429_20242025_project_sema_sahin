#include "main_menu.h"
#include <iostream>
#include <string>
#include <sqlite3.h>

class Application {
public:
    Application() {
        sqlite3* db;
        int exit = sqlite3_open("expense_tracker.db", &db);

        if (exit) {
            std::cout << "\033[31mError opening SQLite database:\033[0m " << sqlite3_errmsg(db) << "\n";
        }
        else {
            std::cout << "\033[32mSuccessfully connected to SQLite database.\nConnection test successful!\033[0m\n";
            sqlite3_close(db);
        }

        system("CLS");
        MainMenu menu;
        menu.handleUserSelection();
    }
};

static Application app;

void MainMenu::displayMenu() {
    std::cout << "\n\033[36m--- Travel Expense Tracker ---\033[0m\n";
    std::cout << "\033[33m1. Register\033[0m\n";
    std::cout << "\033[34m2. Login\033[0m\n";
    std::cout << "\033[35m3. Record Expense\033[0m\n";
    std::cout << "\033[36m4. Generate Summary\033[0m\n";
    std::cout << "\033[32m5. Plan a Trip\033[0m\n";
    std::cout << "\033[31m6. Exit\033[0m\n";
    std::cout << "\033[33m Please select an option:\033[0m\n";
}

void MainMenu::handleUserSelection() {
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            recordExpense();
            break;

        case 4:
            generateSummary();
            break;

        case 5:
            planTrip();
            break;

        case 6:
            std::cout << "\033[31mExiting the application. Goodbye!\033[0m\n";
            break;

        default:
            std::cout << "\033[31mInvalid choice. Please try again.\033[0m\n";
        }
    } while (choice != 6);
}

void MainMenu::registerUser() {
    system("CLS");
    sqlite3* db;
    int exit = sqlite3_open("expense_tracker.db", &db);

    if (exit) {
        std::cout << "\033[31mError opening SQLite database:\033[0m " << sqlite3_errmsg(db) << "\n";
        sqlite3_close(db);
        return;
    }

    std::cout << "\033[36m--- User Registration ---\033[0m\n";
    std::string username, password;
    std::cout << "\033[34mEnter username: \033[0m";
    std::cin >> username;
    std::cout << "\033[34mEnter password: \033[0m";
    std::cin >> password;

    std::string sql = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username TEXT, password TEXT);";
    char* errorMessage;
    exit = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errorMessage);

    if (exit != SQLITE_OK) {
        std::cout << "\033[31mSQL error:\033[0m " << errorMessage << "\n";
        sqlite3_free(errorMessage);
    }
    else {
        sql = "INSERT INTO users (username, password) VALUES ('" + username + "', '" + password + "');";
        exit = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errorMessage);
        if (exit != SQLITE_OK) {
            std::cout << "\033[31mSQL error:\033[0m " << errorMessage << "\n";
            sqlite3_free(errorMessage);
        }
        else {
            std::cout << "\033[32mUser " << username << " registered successfully!\033[0m\n";
        }
    }

    sqlite3_close(db);
}

void MainMenu::loginUser() {
    system("CLS");
    sqlite3* db;
    int exit = sqlite3_open("expense_tracker.db", &db);

    if (exit) {
        std::cout << "\033[31mError opening SQLite database:\033[0m " << sqlite3_errmsg(db) << "\n";
        sqlite3_close(db);
        return;
    }

    std::cout << "\033[36m--- User Login ---\033[0m\n";
    std::string username, password;
    std::cout << "\033[34mEnter username: \033[0m";
    std::cin >> username;
    std::cout << "\033[34mEnter password: \033[0m";
    std::cin >> password;

    std::string sql = "SELECT COUNT(*) FROM users WHERE username = '" + username + "' AND password = '" + password + "';";
    sqlite3_stmt* stmt;
    exit = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (exit != SQLITE_OK) {
        std::cout << "\033[31mSQL error:\033[0m " << sqlite3_errmsg(db) << "\n";
    }
    else {
        sqlite3_step(stmt);
        int count = sqlite3_column_int(stmt, 0);
        if (count > 0) {
            std::cout << "\033[32mUser " << username << " logged in successfully!\033[0m\n";
        }
        else {
            std::cout << "\033[31mInvalid username or password.\033[0m\n";
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void MainMenu::recordExpense() {
    system("CLS");
    std::cout << "\033[36m--- Record Expense ---\033[0m\n";
    std::string category;
    double amount;
    std::cout << "\033[34mEnter expense category: \033[0m";
    std::cin >> category;
    std::cout << "\033[34mEnter expense amount: \033[0m";
    std::cin >> amount;
    std::cout << "\033[32mExpense of " << amount << " in category " << category << " recorded successfully!\033[0m\n";
}

void MainMenu::generateSummary() {
    system("CLS");
    std::cout << "\033[36m--- Generate Summary ---\033[0m\n";
    std::cout << "\033[33mSummary generation functionality coming soon!\033[0m\n";
}

void MainMenu::planTrip() {
    system("CLS");
    std::cout << "\033[36m--- Plan a Trip ---\033[0m\n";
    std::cout << "\033[33mTrip planning functionality coming soon!\033[0m\n";
}
