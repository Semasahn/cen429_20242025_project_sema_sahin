#include "ExpenseRecording.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>

void ExpenseRecording::logExpense(const std::string& category, double amount) {
    // Kategori adý boþ olmamalý, aksi halde hata fýrlatýlýr
    if (category.empty()) {
        throw std::invalid_argument("Category cannot be empty.");
    }

    // Miktar sýfýrdan büyük olmalý, aksi halde hata fýrlatýlýr
    if (amount <= 0.0) {
        throw std::invalid_argument("Amount must be greater than zero.");
    }

    // Kategori adý þifrelenir
    std::string encryptedCategory = encryptDecrypt(category, 'K'); // Encrypt the category

    // Þifrelenmiþ harcama listeye eklenir
    expenses.emplace_back(encryptedCategory, amount); // Add encrypted expense

    // Harcama bilgisi kullanýcýya bildirilir
    std::cout << "Expense logged: " << category << " - $" << std::fixed << std::setprecision(2) << amount << std::endl;
}

const std::vector<std::pair<std::string, double>>& ExpenseRecording::getExpenses() const {
    // Eðer liste boþsa, kullanýcýya uyarý verilir
    if (expenses.empty()) {
        std::cerr << "Warning: No expenses have been recorded yet." << std::endl;
    }
    // Harcamalar döndürülür
    return expenses; // Return the list of expenses
}

double ExpenseRecording::calculateTotalExpenses() const {
    // Eðer liste boþsa, toplam hesaplamasý yapýlmaz ve kullanýcýya uyarý verilir
    if (expenses.empty()) {
        std::cerr << "Warning: No expenses to calculate." << std::endl;
        return 0.0;
    }

    // Harcamalarýn toplamý hesaplanýr
    double total = 0.0;
    for (const auto& expense : expenses) {
        total += expense.second; // Accumulate the amounts
    }

    // Toplam harcama bilgisi kullanýcýya gösterilir
    std::cout << "Total expenses: $" << std::fixed << std::setprecision(2) << total << std::endl;
    return total; // Return the total amount
}

std::string ExpenseRecording::encryptDecrypt(const std::string& input, char key) const {
    // Girdi boþ olmamalý, aksi halde hata fýrlatýlýr
    if (input.empty()) {
        throw std::invalid_argument("Input string cannot be empty.");
    }

    // XOR iþlemi ile þifreleme ve þifre çözme yapýlýr
    std::string output = input;
    for (auto& c : output) {
        c ^= key; // XOR operation for encryption/decryption
    }
    return output;
}

void ExpenseRecording::displayExpenses() const {
    // Eðer liste boþsa, kullanýcýya bilgi verilir
    if (expenses.empty()) {
        std::cout << "No expenses to display." << std::endl;
        return;
    }

    // Harcama listesi formatlý þekilde ekrana yazdýrýlýr
    std::cout << "Recorded Expenses:\n";
    std::cout << std::left << std::setw(20) << "Category" << std::right << std::setw(10) << "Amount" << std::endl;
    std::cout << std::string(30, '-') << std::endl;

    for (const auto& expense : expenses) {
        // Þifrelenmiþ kategori adý çözülerek gösterilir
        std::string decryptedCategory = encryptDecrypt(expense.first, 'K');
        std::cout << std::left << std::setw(20) << decryptedCategory
            << "$" << std::fixed << std::setprecision(2) << expense.second << std::endl;
    }
}

void ExpenseRecording::deleteExpense(const std::string& category) {
    // Kategori adý boþ olmamalý, aksi halde hata fýrlatýlýr
    if (category.empty()) {
        throw std::invalid_argument("Category cannot be empty.");
    }

    // Silinecek kategori þifrelenir
    std::string encryptedCategory = encryptDecrypt(category, 'K');

    // Verilen kategoriye ait harcamalar listeden kaldýrýlýr
    auto it = std::remove_if(expenses.begin(), expenses.end(), [&](const auto& expense) {
        return expense.first == encryptedCategory;
        });

    if (it != expenses.end()) {
        // Harcamalar baþarýyla silinirse kullanýcýya bilgi verilir
        expenses.erase(it, expenses.end());
        std::cout << "Expense with category '" << category << "' has been deleted." << std::endl;
    }
    else {
        // Eðer kategori bulunamazsa kullanýcýya bilgi verilir
        std::cout << "No expense found for the category '" << category << "'." << std::endl;
    }
}

void ExpenseRecording::clearExpenses() {
    // Tüm harcamalar listeden temizlenir
    expenses.clear();
    std::cout << "All expenses have been cleared." << std::endl;
}

// Sýnýfýn iþlevselliðini göstermek için örnek kullaným
void ExpenseRecording::exampleUsage() {
    try {
        // Örnek harcamalar kaydedilir
        logExpense("Food", 12.50);
        logExpense("Transport", 8.75);
        logExpense("Entertainment", 25.00);

        // Harcamalar görüntülenir
        displayExpenses();

        // Toplam harcamalar hesaplanýr
        calculateTotalExpenses();

        // Belirli bir kategori silinir
        deleteExpense("Transport");
        displayExpenses();

        // Tüm harcamalar temizlenir
        clearExpenses();
        displayExpenses();


    }
    catch (const std::exception& e) {
        // Hata durumunda mesaj gösterilir
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
