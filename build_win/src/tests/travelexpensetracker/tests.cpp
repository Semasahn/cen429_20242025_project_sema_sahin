#include "BudgetManagement.h"
#include "TripPlanning.h"
#include "UserAuthentication.h"
#include "ExpenseRecording.h"
#include "SummaryReport.h"
#include "main_menu.h"
#include "gtest/gtest.h"
#include <sstream>
#include <string>

// Test: B�t�e Ayarlama
TEST(BudgetManagementTest, SetBudget) {
    BudgetManagement manager;
    manager.setBudget(500.0);
    EXPECT_DOUBLE_EQ(manager.viewBudget(), 500.0);
}

// Test: Negatif B�t�e Ayarlama
TEST(BudgetManagementTest, SetNegativeBudget) {
    BudgetManagement manager;
    manager.setBudget(-100.0);
    EXPECT_DOUBLE_EQ(manager.viewBudget(), 0.0); // Negatif b�t�e ayarlanmaz, varsay�lan kal�r
}

// Test: B�t�e D�zenleme
TEST(BudgetManagementTest, EditBudget) {
    BudgetManagement manager;
    manager.setBudget(1000.0);
    manager.editBudget(1500.0);
    EXPECT_DOUBLE_EQ(manager.viewBudget(), 1500.0);
}

// Test: Negatif B�t�e D�zenleme
TEST(BudgetManagementTest, EditNegativeBudget) {
    BudgetManagement manager;
    manager.setBudget(1000.0);
    manager.editBudget(-200.0);
    EXPECT_DOUBLE_EQ(manager.viewBudget(), 1000.0); // Negatif de�erle d�zenlenemez
}

// Test s�n�f�
// Test fixture for TripPlanning
class TripPlanningTest : public ::testing::Test {
protected:
    TripPlanning tripPlanner;
};

// Test to verify trip creation
TEST_F(TripPlanningTest, CreateTrip) {
    std::string destination = "Paris";

    EXPECT_NO_THROW({
        tripPlanner.createTrip(destination); // Ensure no exceptions are thrown
        });

    auto trips = tripPlanner.getTrips();
    ASSERT_EQ(trips.size(), 1) << "Trips list should contain one entry.";
    std::string decryptedDestination = tripPlanner.decryptData(trips[0], "SecureKey1234");
    EXPECT_EQ(decryptedDestination, destination) << "Decrypted trip should match the original destination.";
}

// Test to verify viewing trips
TEST_F(TripPlanningTest, ViewTrips) {
    tripPlanner.createTrip("New York");
    tripPlanner.createTrip("London");

    EXPECT_NO_THROW({
        tripPlanner.viewTrips(); // Ensure no exceptions are thrown
        });

    auto trips = tripPlanner.getTrips();
    ASSERT_EQ(trips.size(), 2) << "Trips list should contain two entries.";
    EXPECT_EQ(tripPlanner.decryptData(trips[0], "SecureKey1234"), "New York") << "First trip should match.";
    EXPECT_EQ(tripPlanner.decryptData(trips[1], "SecureKey1234"), "London") << "Second trip should match.";
}

// Test to verify editing trips
TEST_F(TripPlanningTest, EditTrip) {
    tripPlanner.createTrip("Berlin");

    EXPECT_TRUE(tripPlanner.editTrip(1, "Tokyo")) << "Editing trip should succeed.";
    auto trips = tripPlanner.getTrips();
    std::string decryptedDestination = tripPlanner.decryptData(trips[0], "SecureKey1234");
    EXPECT_EQ(decryptedDestination, "Tokyo") << "Decrypted trip should match the new destination.";

    EXPECT_FALSE(tripPlanner.editTrip(2, "Moscow")) << "Editing non-existent trip should fail.";
}

// Test to verify deleting trips
TEST_F(TripPlanningTest, DeleteTrip) {
    tripPlanner.createTrip("Amsterdam");
    tripPlanner.createTrip("Dubai");

    EXPECT_TRUE(tripPlanner.deleteTrip(1)) << "Deleting trip should succeed.";
    auto trips = tripPlanner.getTrips();
    ASSERT_EQ(trips.size(), 1) << "Trips list should contain one entry after deletion.";
    EXPECT_EQ(tripPlanner.decryptData(trips[0], "SecureKey1234"), "Dubai") << "Remaining trip should match.";

    EXPECT_FALSE(tripPlanner.deleteTrip(3)) << "Deleting non-existent trip should fail.";
}

// Test to verify encryption and decryption
TEST_F(TripPlanningTest, EncryptDecryptData) {
    std::string data = "Test Destination";
    std::string key = "SecureKey1234";

    std::string encryptedData = tripPlanner.encryptData(data, key);
    EXPECT_NE(data, encryptedData) << "Encrypted data should not match the original data.";

    std::string decryptedData = tripPlanner.decryptData(encryptedData, key);
    EXPECT_EQ(data, decryptedData) << "Decrypted data should match the original data.";
}

// Test to ensure empty destination throws an exception
TEST_F(TripPlanningTest, CreateTripEmptyDestination) {
    EXPECT_THROW({
        tripPlanner.createTrip("");
        }, std::invalid_argument) << "Creating a trip with an empty destination should throw an exception.";
}

// Test to ensure editing with an empty destination throws an exception
TEST_F(TripPlanningTest, EditTripEmptyDestination) {
    tripPlanner.createTrip("Rome");

    EXPECT_THROW({
        tripPlanner.editTrip(1, "");
        }, std::invalid_argument) << "Editing a trip with an empty destination should throw an exception.";
}

// Test s�n�f�
class UserAuthenticationTest : public ::testing::Test {
protected:
    UserAuthentication auth; // Testlerde kullan�lacak UserAuthentication nesnesi
};

// **TEST 1:** Kullan�c� giri� testi
TEST_F(UserAuthenticationTest, LoginReturnsTrueForValidCredentials) {
    testing::internal::CaptureStdout(); // ��kt�y� yakalamak i�in
    bool result = auth.login("testuser", "password123");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(result) << "Ge�erli kullan�c� ad� ve �ifre ile giri� ba�ar�l� olmal�.";
    EXPECT_NE(output.find("Logging in user: testuser"), std::string::npos)
        << "Giri� mesaj� do�ru olmal�.";
}

// **TEST 2:** Kullan�c� kay�t testi
TEST_F(UserAuthenticationTest, RegisterUserReturnsTrueForValidDetails) {
    testing::internal::CaptureStdout(); // ��kt�y� yakalamak i�in
    bool result = auth.registerUser("newuser", "newpassword");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(result) << "Ge�erli kullan�c� ad� ve �ifre ile kay�t ba�ar�l� olmal�.";
    EXPECT_NE(output.find("Registering user: newuser"), std::string::npos)
        << "Kay�t mesaj� do�ru olmal�.";
}

// **TEST 3:** Misafir modu testi
TEST_F(UserAuthenticationTest, GuestModeOutputsCorrectMessage) {
    testing::internal::CaptureStdout(); // ��kt�y� yakalamak i�in
    auth.guestMode();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Entering guest mode..."), std::string::npos)
        << "Misafir modu mesaj� do�ru olmal�.";
}


// Bo� harcama listesi testi
TEST(ExpenseRecordingTest, EmptyExpenses) {
    ExpenseRecording recorder;

    // Toplam harcama bo� oldu�unda 0 olmal�
    EXPECT_DOUBLE_EQ(recorder.calculateTotalExpenses(), 0.0);

    // Harcama listesi bo� olmal�
    EXPECT_TRUE(recorder.getExpenses().empty());
}

// Helper s�n�f�: std::cout ��kt�s�n� yakalamak i�in
class CoutRedirect {
    std::streambuf* old_buf;
    std::ostringstream temp_stream;

public:
    CoutRedirect() {
        old_buf = std::cout.rdbuf(temp_stream.rdbuf()); // std::cout'u yakala
    }

    ~CoutRedirect() {
        std::cout.rdbuf(old_buf); // std::cout'u eski haline getir
    }

    std::string getOutput() {
        return temp_stream.str();
    }
};