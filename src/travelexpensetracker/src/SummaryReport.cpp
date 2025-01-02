#include "SummaryReport.h"
#include <iostream>
#include <stdexcept>

void SummaryReport::generateReport() const {
    // Rapor verisi olu�turulur (�rnek veri)
    std::string report = "Sample report data: Expenses summary.";
    std::cout << "Generating report..." << std::endl;

    // Rapor verisi �ifrelenir
    std::string encryptedReport = encryptReportData(report, whiteboxKey);
    std::cout << "Report encrypted: " << encryptedReport << std::endl;

    // �ifre ��zme i�lemi (g�sterim ama�l�)
    std::string decryptedReport = decryptReportData(encryptedReport, whiteboxKey);
    std::cout << "Decrypted report: " << decryptedReport << std::endl;

    // Rapor olu�turma i�lemi tamamlan�r
    std::cout << "Report generation completed successfully." << std::endl;
}

void SummaryReport::viewReports() const {
    // Mevcut raporlar�n g�r�nt�lenmesi i�lemi ba�lat�l�r
    std::cout << "Viewing reports..." << std::endl;

    // Hen�z eklenmemi� placeholder mant�k
    std::cout << "No reports available to display." << std::endl;

    // Rapor g�r�nt�leme i�lemi tamamlan�r
    std::cout << "Report viewing process completed." << std::endl;
}

std::string SummaryReport::encryptReportData(const std::string& data, const std::string& key) const {
    // �ifreleme anahtar� kontrol edilir, bo�sa hata f�rlat�l�r
    if (key.empty()) {
        throw std::invalid_argument("Encryption key cannot be empty");
    }

    // XOR �ifreleme i�lemi uygulan�r
    std::string encrypted = data;
    for (size_t i = 0; i < data.size(); ++i) {
        encrypted[i] ^= key[i % key.size()]; // XOR her karakter i�in uygulan�r
    }

    // �ifrelenmi� veri d�nd�r�l�r
    return encrypted;
}

std::string SummaryReport::decryptReportData(const std::string& encryptedData, const std::string& key) const {
    // XOR �ifreleme tersinir bir i�lemdir, bu nedenle ayn� y�ntem kullan�l�r
    return encryptReportData(encryptedData, key); // XOR decryption is the same as encryption
}
