#include "TripPlanning.h"
#include <iostream>
#include <stdexcept>

// Gezi oluþturma
void TripPlanning::createTrip(const std::string& destination) {
    if (destination.empty()) {
        throw std::invalid_argument("Destination cannot be empty.");
    }

    // Destination is encrypted before being stored
    std::string encryptedDestination = encryptData(destination, whiteboxKey);
    trips.push_back(encryptedDestination);
    std::cout << "Trip to " << destination << " created." << std::endl;
}

// Gezileri görüntüleme
void TripPlanning::viewTrips() const {
    std::cout << "Current trips: " << std::endl;

    for (size_t i = 0; i < trips.size(); ++i) {
        // Decrypt each trip for display
        std::string decryptedDestination = decryptData(trips[i], whiteboxKey);
        std::cout << i + 1 << ". " << decryptedDestination << std::endl;
    }
}

// Gezi düzenleme
bool TripPlanning::editTrip(int tripId, const std::string& newDestination) {
    if (tripId > 0 && tripId <= static_cast<int>(trips.size())) {
        if (newDestination.empty()) {
            throw std::invalid_argument("New destination cannot be empty.");
        }

        // Encrypt the new destination before updating
        trips[tripId - 1] = encryptData(newDestination, whiteboxKey);
        std::cout << "Trip updated to: " << newDestination << std::endl;
        return true; // Düzenleme baþarýlý
    }
    else {
        std::cout << "Invalid trip ID." << std::endl;
        return false; // Düzenleme baþarýsýz
    }
}

// Gezi silme
bool TripPlanning::deleteTrip(int tripId) {
    if (tripId > 0 && tripId <= static_cast<int>(trips.size())) {
        trips.erase(trips.begin() + tripId - 1);
        std::cout << "Trip deleted." << std::endl;
        return true; // Silme baþarýlý
    }
    else {
        std::cout << "Invalid trip ID." << std::endl;
        return false; // Silme baþarýsýz
    }
}

// Tüm gezileri alma (getter)
const std::vector<std::string>& TripPlanning::getTrips() const {
    return trips;
}

// Þifreleme iþlevi
std::string TripPlanning::encryptData(const std::string& data, const std::string& key) const {
    if (key.empty()) {
        throw std::invalid_argument("Encryption key cannot be empty.");
    }

    std::string encrypted = data;
    for (size_t i = 0; i < data.size(); ++i) {
        encrypted[i] ^= key[i % key.size()]; // XOR encryption
    }
    return encrypted;
}

// Þifre çözme iþlevi
std::string TripPlanning::decryptData(const std::string& encryptedData, const std::string& key) const {
    return encryptData(encryptedData, key); // XOR decryption is the same as encryption
}
