/*#include "TripPlanning.h"
#include <gtest/gtest.h>
#include <stdexcept>

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
    EXPECT_EQ(tripPlanner.decryptData(trips[0], "SecureKey1234"), destination) << "Decrypted trip should match the original destination.";
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
}

// Test to verify editing trips
TEST_F(TripPlanningTest, EditTrip) {
    tripPlanner.createTrip("Berlin");

    EXPECT_TRUE(tripPlanner.editTrip(1, "Tokyo")) << "Editing trip should succeed.";
    auto trips = tripPlanner.getTrips();
    EXPECT_EQ(tripPlanner.decryptData(trips[0], "SecureKey1234"), "Tokyo") << "Decrypted trip should match the new destination.";

    EXPECT_FALSE(tripPlanner.editTrip(2, "Moscow")) << "Editing non-existent trip should fail.";
}

// Test to verify deleting trips
TEST_F(TripPlanningTest, DeleteTrip) {
    tripPlanner.createTrip("Amsterdam");
    tripPlanner.createTrip("Dubai");

    EXPECT_TRUE(tripPlanner.deleteTrip(1)) << "Deleting trip should succeed.";
    auto trips = tripPlanner.getTrips();
    ASSERT_EQ(trips.size(), 1) << "Trips list should contain one entry after deletion.";

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
*/
