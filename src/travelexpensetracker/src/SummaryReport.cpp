#include "SummaryReport.h"
#include <iostream>
#include <stdexcept>

void SummaryReport::generateReport() const {
    // Rapor verisi oluþturulur (örnek veri)
    std::string report = "Sample report data: Expenses summary.";
    std::cout << "Generating report..." << std::endl;

    // Rapor verisi þifrelenir
    std::string encryptedReport = encryptReportData(report, whiteboxKey);
    std::cout << "Report encrypted: " << encryptedReport << std::endl;

    // Þifre çözme iþlemi (gösterim amaçlý)
    std::string decryptedReport = decryptReportData(encryptedReport, whiteboxKey);
    std::cout << "Decrypted report: " << decryptedReport << std::endl;

    // Rapor oluþturma iþlemi tamamlanýr
    std::cout << "Report generation completed successfully." << std::endl;
}

void SummaryReport::viewReports() const {
    // Mevcut raporlarýn görüntülenmesi iþlemi baþlatýlýr
    std::cout << "Viewing reports..." << std::endl;

    // Henüz eklenmemiþ placeholder mantýk
    std::cout << "No reports available to display." << std::endl;

    // Rapor görüntüleme iþlemi tamamlanýr
    std::cout << "Report viewing process completed." << std::endl;
}

std::string SummaryReport::encryptReportData(const std::string& data, const std::string& key) const {
    // Þifreleme anahtarý kontrol edilir, boþsa hata fýrlatýlýr
    if (key.empty()) {
        throw std::invalid_argument("Encryption key cannot be empty");
    }

    // XOR þifreleme iþlemi uygulanýr
    std::string encrypted = data;
    for (size_t i = 0; i < data.size(); ++i) {
        encrypted[i] ^= key[i % key.size()]; // XOR her karakter için uygulanýr
    }

    // Þifrelenmiþ veri döndürülür
    return encrypted;
}

std::string SummaryReport::decryptReportData(const std::string& encryptedData, const std::string& key) const {
    // XOR þifreleme tersinir bir iþlemdir, bu nedenle ayný yöntem kullanýlýr
    return encryptReportData(encryptedData, key); // XOR decryption is the same as encryption
}
