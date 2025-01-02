#ifndef SUMMARY_REPORT_H
#define SUMMARY_REPORT_H

#include <string>

class SummaryReport {
public:
    // Rapor oluþturmak için kullanýlan fonksiyon
    void generateReport() const;

    // Mevcut raporlarý görüntülemek için kullanýlan fonksiyon
    void viewReports() const;

    // Rapor verilerini þifrelemek için kullanýlan yardýmcý fonksiyon
    std::string encryptReportData(const std::string& data, const std::string& key) const;

    // Þifrelenmiþ rapor verilerini çözmek için kullanýlan yardýmcý fonksiyon
    std::string decryptReportData(const std::string& encryptedData, const std::string& key) const;

    // Þifreleme ve þifre çözme için kullanýlan anahtar
    const std::string whiteboxKey = "SampleKey1234"; // Örnek þifreleme anahtarý
};

#endif // SUMMARY_REPORT_H
