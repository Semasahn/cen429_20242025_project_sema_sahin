#ifndef TRIP_PLANNING_H
#define TRIP_PLANNING_H

#include <string>
#include <vector>

class TripPlanning {
public:
    // Gezi olu�turma fonksiyonu
    void createTrip(const std::string& destination);

    // T�m gezileri g�r�nt�leme fonksiyonu
    void viewTrips() const;

    // Gezi d�zenleme fonksiyonu (tripId ve yeni hedef al�r)
    bool editTrip(int tripId, const std::string& newDestination);

    // Gezi silme fonksiyonu (tripId al�r)
    bool deleteTrip(int tripId);

    // T�m gezileri d�nd�ren getter fonksiyonu
    const std::vector<std::string>& getTrips() const;

    // �ifreleme i�levi
    std::string encryptData(const std::string& data, const std::string& key) const;

    // �ifre ��zme i�levi
    std::string decryptData(const std::string& encryptedData, const std::string& key) const;

    // Gezi listesi (�ifrelenmi� veri i�erir)
    std::vector<std::string> trips;

    // Whitebox g�venlik anahtar�
    const std::string whiteboxKey = "SecureKey1234"; // �rnek anahtar
};

#endif // TRIP_PLANNING_H
