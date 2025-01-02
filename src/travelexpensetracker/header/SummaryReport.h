#ifndef SUMMARY_REPORT_H
#define SUMMARY_REPORT_H

#include <string>

class SummaryReport {
public:
    // Rapor olu�turmak i�in kullan�lan fonksiyon
    void generateReport() const;

    // Mevcut raporlar� g�r�nt�lemek i�in kullan�lan fonksiyon
    void viewReports() const;

    // Rapor verilerini �ifrelemek i�in kullan�lan yard�mc� fonksiyon
    std::string encryptReportData(const std::string& data, const std::string& key) const;

    // �ifrelenmi� rapor verilerini ��zmek i�in kullan�lan yard�mc� fonksiyon
    std::string decryptReportData(const std::string& encryptedData, const std::string& key) const;

    // �ifreleme ve �ifre ��zme i�in kullan�lan anahtar
    const std::string whiteboxKey = "SampleKey1234"; // �rnek �ifreleme anahtar�
};

#endif // SUMMARY_REPORT_H
