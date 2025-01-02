#ifndef EXPENSE_RECORDING_H
#define EXPENSE_RECORDING_H

#include <string>
#include <vector>
#include <utility>

class ExpenseRecording {
public:
    // Harcama kaydý eklemek için kullanýlacak fonksiyon
    void logExpense(const std::string& category, double amount);

    // Kaydedilen harcamalarýn listesini döndürür
    const std::vector<std::pair<std::string, double>>& getExpenses() const;

    // Tüm harcamalarýn toplam miktarýný hesaplar
    double calculateTotalExpenses() const;

    // Kaydedilen harcamalarý kullanýcý dostu bir formatta gösterir
    void displayExpenses() const;

    // Verilen kategoriye ait harcamayý siler
    void deleteExpense(const std::string& category);

    // Tüm harcamalarý temizler
    void clearExpenses();

    // Sýnýfýn iþlevselliðini göstermek için örnek bir kullaným
    void exampleUsage();

    // Þifreleme ve þifre çözme iþlemleri için kullanýlan yardýmcý fonksiyon
    std::string encryptDecrypt(const std::string& input, char key) const;

    // Þifrelenmiþ kategori ve miktar çiftlerini tutan harcama listesi
    std::vector<std::pair<std::string, double>> expenses;
};

#endif // EXPENSE_RECORDING_H
