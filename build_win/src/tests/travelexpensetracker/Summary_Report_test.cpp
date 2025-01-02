#include "SummaryReport.h"
#include <gtest/gtest.h>
#include <stdexcept>

// Test fixture for SummaryReport
class SummaryReportTest : public ::testing::Test {
protected:
    SummaryReport report;
};

// Test to verify report generation
TEST_F(SummaryReportTest, GenerateReport) {
    EXPECT_NO_THROW({
        report.generateReport(); // Ensure no exceptions are thrown during report generation
        });
}

// Test to verify encryption functionality
TEST_F(SummaryReportTest, EncryptReportData) {
    std::string data = "Test Data";
    std::string key = "Key123";

    std::string encryptedData = report.encryptReportData(data, key);
    EXPECT_NE(data, encryptedData) << "Encrypted data should not match the original data.";

    // Verify encryption with different keys produces different outputs
    std::string differentKey = "Key456";
    std::string encryptedWithDifferentKey = report.encryptReportData(data, differentKey);
    EXPECT_NE(encryptedData, encryptedWithDifferentKey) << "Encryption with a different key should produce different results.";
}

// Test to verify decryption functionality
TEST_F(SummaryReportTest, DecryptReportData) {
    std::string data = "Test Data";
    std::string key = "Key123";

    std::string encryptedData = report.encryptReportData(data, key);
    std::string decryptedData = report.decryptReportData(encryptedData, key);

    EXPECT_EQ(data, decryptedData) << "Decrypted data should match the original data.";

    // Verify decryption with a wrong key fails to produce original data
    std::string wrongKey = "WrongKey";
    std::string wronglyDecryptedData = report.decryptReportData(encryptedData, wrongKey);
    EXPECT_NE(data, wronglyDecryptedData) << "Decryption with the wrong key should not produce the original data.";
}

// Test to ensure an empty encryption key throws an exception
TEST_F(SummaryReportTest, EncryptWithEmptyKey) {
    std::string data = "Test Data";
    std::string emptyKey = "";

    EXPECT_THROW(
        {
            report.encryptReportData(data, emptyKey);
        },
        std::invalid_argument
    ) << "Encrypting with an empty key should throw an exception.";
}

// Test to ensure viewing reports does not throw an exception
TEST_F(SummaryReportTest, ViewReports) {
    EXPECT_NO_THROW({
        report.viewReports(); // Ensure no exceptions are thrown when viewing reports
        });

    // Simulate additional report viewing logic
    std::cout << "Testing viewReports completed." << std::endl;
}

// Test to ensure encryption and decryption are reversible for various data lengths
TEST_F(SummaryReportTest, EncryptDecryptVariousLengths) {
    std::vector<std::string> testCases = {
        "", // Empty string
        "A", // Single character
        "Short test string",
        std::string(1000, 'A') // Very long string
    };

    std::string key = "Key123";
    for (const auto& data : testCases) {
        std::string encryptedData = report.encryptReportData(data, key);
        std::string decryptedData = report.decryptReportData(encryptedData, key);
        EXPECT_EQ(data, decryptedData) << "Decrypted data should match the original for input: " << data;
    }
}