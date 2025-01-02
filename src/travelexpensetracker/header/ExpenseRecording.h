#ifndef EXPENSE_RECORDING_H
#define EXPENSE_RECORDING_H

#include <string>
#include <vector>
#include <utility>

class ExpenseRecording {
public:
    // Harcama kayd� eklemek i�in kullan�lacak fonksiyon
    void logExpense(const std::string& category, double amount);

    // Kaydedilen harcamalar�n listesini d�nd�r�r
    const std::vector<std::pair<std::string, double>>& getExpenses() const;

    // T�m harcamalar�n toplam miktar�n� hesaplar
    double calculateTotalExpenses() const;

    // Kaydedilen harcamalar� kullan�c� dostu bir formatta g�sterir
    void displayExpenses() const;

    // Verilen kategoriye ait harcamay� siler
    void deleteExpense(const std::string& category);

    // T�m harcamalar� temizler
    void clearExpenses();

    // S�n�f�n i�levselli�ini g�stermek i�in �rnek bir kullan�m
    void exampleUsage();

    // �ifreleme ve �ifre ��zme i�lemleri i�in kullan�lan yard�mc� fonksiyon
    std::string encryptDecrypt(const std::string& input, char key) const;

    // �ifrelenmi� kategori ve miktar �iftlerini tutan harcama listesi
    std::vector<std::pair<std::string, double>> expenses;
};

#endif // EXPENSE_RECORDING_H
