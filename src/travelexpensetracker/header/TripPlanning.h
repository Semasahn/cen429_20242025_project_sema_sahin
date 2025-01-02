#ifndef TRIP_PLANNING_H
#define TRIP_PLANNING_H

#include <string>
#include <vector>

class TripPlanning {
public:
    // Gezi oluþturma fonksiyonu
    void createTrip(const std::string& destination);

    // Tüm gezileri görüntüleme fonksiyonu
    void viewTrips() const;

    // Gezi düzenleme fonksiyonu (tripId ve yeni hedef alýr)
    bool editTrip(int tripId, const std::string& newDestination);

    // Gezi silme fonksiyonu (tripId alýr)
    bool deleteTrip(int tripId);

    // Tüm gezileri döndüren getter fonksiyonu
    const std::vector<std::string>& getTrips() const;

    // Þifreleme iþlevi
    std::string encryptData(const std::string& data, const std::string& key) const;

    // Þifre çözme iþlevi
    std::string decryptData(const std::string& encryptedData, const std::string& key) const;

    // Gezi listesi (þifrelenmiþ veri içerir)
    std::vector<std::string> trips;

    // Whitebox güvenlik anahtarý
    const std::string whiteboxKey = "SecureKey1234"; // Örnek anahtar
};

#endif // TRIP_PLANNING_H
