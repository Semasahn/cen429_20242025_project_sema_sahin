#ifndef USER_AUTHENTICATION_H
#define USER_AUTHENTICATION_H

#include <string>

class UserAuthentication {
public:
    // Kullanýcý giriþi için iþlev
    bool login(const std::string& username, const std::string& password);

    // Kullanýcý kaydý için iþlev
    bool registerUser(const std::string& username, const std::string& password);

    // Misafir modu iþlevi
    void guestMode();

private:
    // Ek güvenlik adýmlarý için kullanýlan matematiksel iþlemler burada uygulanýr.
};

#endif // USER_AUTHENTICATION_H
