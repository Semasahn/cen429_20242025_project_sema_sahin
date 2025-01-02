#include "ExpenseRecording.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>

void ExpenseRecording::logExpense(const std::string& category, double amount) {
    // Kategori ad� bo� olmamal�, aksi halde hata f�rlat�l�r
    if (category.empty()) {
        throw std::invalid_argument("Category cannot be empty.");
    }

    // Miktar s�f�rdan b�y�k olmal�, aksi halde hata f�rlat�l�r
    if (amount <= 0.0) {
        throw std::invalid_argument("Amount must be greater than zero.");
    }

    // Kategori ad� �ifrelenir
    std::string encryptedCategory = encryptDecrypt(category, 'K'); // Encrypt the category

    // �ifrelenmi� harcama listeye eklenir
    expenses.emplace_back(encryptedCategory, amount); // Add encrypted expense

    // Harcama bilgisi kullan�c�ya bildirilir
    std::cout << "Expense logged: " << category << " - $" << std::fixed << std::setprecision(2) << amount << std::endl;
}

const std::vector<std::pair<std::string, double>>& ExpenseRecording::getExpenses() const {
    // E�er liste bo�sa, kullan�c�ya uyar� verilir
    if (expenses.empty()) {
        std::cerr << "Warning: No expenses have been recorded yet." << std::endl;
    }
    // Harcamalar d�nd�r�l�r
    return expenses; // Return the list of expenses
}

double ExpenseRecording::calculateTotalExpenses() const {
    // E�er liste bo�sa, toplam hesaplamas� yap�lmaz ve kullan�c�ya uyar� verilir
    if (expenses.empty()) {
        std::cerr << "Warning: No expenses to calculate." << std::endl;
        return 0.0;
    }

    // Harcamalar�n toplam� hesaplan�r
    double total = 0.0;
    for (const auto& expense : expenses) {
        total += expense.second; // Accumulate the amounts
    }

    // Toplam harcama bilgisi kullan�c�ya g�sterilir
    std::cout << "Total expenses: $" << std::fixed << std::setprecision(2) << total << std::endl;
    return total; // Return the total amount
}

std::string ExpenseRecording::encryptDecrypt(const std::string& input, char key) const {
    // Girdi bo� olmamal�, aksi halde hata f�rlat�l�r
    if (input.empty()) {
        throw std::invalid_argument("Input string cannot be empty.");
    }

    // XOR i�lemi ile �ifreleme ve �ifre ��zme yap�l�r
    std::string output = input;
    for (auto& c : output) {
        c ^= key; // XOR operation for encryption/decryption
    }
    return output;
}

void ExpenseRecording::displayExpenses() const {
    // E�er liste bo�sa, kullan�c�ya bilgi verilir
    if (expenses.empty()) {
        std::cout << "No expenses to display." << std::endl;
        return;
    }

    // Harcama listesi formatl� �ekilde ekrana yazd�r�l�r
    std::cout << "Recorded Expenses:\n";
    std::cout << std::left << std::setw(20) << "Category" << std::right << std::setw(10) << "Amount" << std::endl;
    std::cout << std::string(30, '-') << std::endl;

    for (const auto& expense : expenses) {
        // �ifrelenmi� kategori ad� ��z�lerek g�sterilir
        std::string decryptedCategory = encryptDecrypt(expense.first, 'K');
        std::cout << std::left << std::setw(20) << decryptedCategory
            << "$" << std::fixed << std::setprecision(2) << expense.second << std::endl;
    }
}

void ExpenseRecording::deleteExpense(const std::string& category) {
    // Kategori ad� bo� olmamal�, aksi halde hata f�rlat�l�r
    if (category.empty()) {
        throw std::invalid_argument("Category cannot be empty.");
    }

    // Silinecek kategori �ifrelenir
    std::string encryptedCategory = encryptDecrypt(category, 'K');

    // Verilen kategoriye ait harcamalar listeden kald�r�l�r
    auto it = std::remove_if(expenses.begin(), expenses.end(), [&](const auto& expense) {
        return expense.first == encryptedCategory;
        });

    if (it != expenses.end()) {
        // Harcamalar ba�ar�yla silinirse kullan�c�ya bilgi verilir
        expenses.erase(it, expenses.end());
        std::cout << "Expense with category '" << category << "' has been deleted." << std::endl;
    }
    else {
        // E�er kategori bulunamazsa kullan�c�ya bilgi verilir
        std::cout << "No expense found for the category '" << category << "'." << std::endl;
    }
}

void ExpenseRecording::clearExpenses() {
    // T�m harcamalar listeden temizlenir
    expenses.clear();
    std::cout << "All expenses have been cleared." << std::endl;
}

// S�n�f�n i�levselli�ini g�stermek i�in �rnek kullan�m
void ExpenseRecording::exampleUsage() {
    try {
        // �rnek harcamalar kaydedilir
        logExpense("Food", 12.50);
        logExpense("Transport", 8.75);
        logExpense("Entertainment", 25.00);

        // Harcamalar g�r�nt�lenir
        displayExpenses();

        // Toplam harcamalar hesaplan�r
        calculateTotalExpenses();

        // Belirli bir kategori silinir
        deleteExpense("Transport");
        displayExpenses();

        // T�m harcamalar temizlenir
        clearExpenses();
        displayExpenses();


    }
    catch (const std::exception& e) {
        // Hata durumunda mesaj g�sterilir
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
