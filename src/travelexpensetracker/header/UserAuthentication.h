#ifndef USER_AUTHENTICATION_H
#define USER_AUTHENTICATION_H

#include <string>

class UserAuthentication {
public:
    // Kullan�c� giri�i i�in i�lev
    bool login(const std::string& username, const std::string& password);

    // Kullan�c� kayd� i�in i�lev
    bool registerUser(const std::string& username, const std::string& password);

    // Misafir modu i�levi
    void guestMode();

private:
    // Ek g�venlik ad�mlar� i�in kullan�lan matematiksel i�lemler burada uygulan�r.
};

#endif // USER_AUTHENTICATION_H
