#include "TripPlanning.h"
#include <iostream>
#include <stdexcept>

// Gezi olu�turma
void TripPlanning::createTrip(const std::string& destination) {
    if (destination.empty()) {
        throw std::invalid_argument("Destination cannot be empty.");
    }

    // Destination is encrypted before being stored
    std::string encryptedDestination = encryptData(destination, whiteboxKey);
    trips.push_back(encryptedDestination);
    std::cout << "Trip to " << destination << " created." << std::endl;
}

// Gezileri g�r�nt�leme
void TripPlanning::viewTrips() const {
    std::cout << "Current trips: " << std::endl;

    for (size_t i = 0; i < trips.size(); ++i) {
        // Decrypt each trip for display
        std::string decryptedDestination = decryptData(trips[i], whiteboxKey);
        std::cout << i + 1 << ". " << decryptedDestination << std::endl;
    }
}

// Gezi d�zenleme
bool TripPlanning::editTrip(int tripId, const std::string& newDestination) {
    if (tripId > 0 && tripId <= static_cast<int>(trips.size())) {
        if (newDestination.empty()) {
            throw std::invalid_argument("New destination cannot be empty.");
        }

        // Encrypt the new destination before updating
        trips[tripId - 1] = encryptData(newDestination, whiteboxKey);
        std::cout << "Trip updated to: " << newDestination << std::endl;
        return true; // D�zenleme ba�ar�l�
    }
    else {
        std::cout << "Invalid trip ID." << std::endl;
        return false; // D�zenleme ba�ar�s�z
    }
}

// Gezi silme
bool TripPlanning::deleteTrip(int tripId) {
    if (tripId > 0 && tripId <= static_cast<int>(trips.size())) {
        trips.erase(trips.begin() + tripId - 1);
        std::cout << "Trip deleted." << std::endl;
        return true; // Silme ba�ar�l�
    }
    else {
        std::cout << "Invalid trip ID." << std::endl;
        return false; // Silme ba�ar�s�z
    }
}

// T�m gezileri alma (getter)
const std::vector<std::string>& TripPlanning::getTrips() const {
    return trips;
}

// �ifreleme i�levi
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

// �ifre ��zme i�levi
std::string TripPlanning::decryptData(const std::string& encryptedData, const std::string& key) const {
    return encryptData(encryptedData, key); // XOR decryption is the same as encryption
}
