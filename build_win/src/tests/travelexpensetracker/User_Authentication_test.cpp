//#include "UserAuthentication.h"
//#include "gtest/gtest.h"
//#include <sstream>
//
//// Test sýnýfý
//class UserAuthenticationTest : public ::testing::Test {
//protected:
//    UserAuthentication auth; // Testlerde kullanýlacak UserAuthentication nesnesi
//};
//
//// **TEST 1:** Kullanýcý giriþ testi
//TEST_F(UserAuthenticationTest, LoginReturnsTrueForValidCredentials) {
//    testing::internal::CaptureStdout(); // Çýktýyý yakalamak için
//    bool result = auth.login("testuser", "password123");
//    std::string output = testing::internal::GetCapturedStdout();
//
//    EXPECT_TRUE(result) << "Geçerli kullanýcý adý ve þifre ile giriþ baþarýlý olmalý.";
//    EXPECT_NE(output.find("Logging in user: testuser"), std::string::npos)
//        << "Giriþ mesajý doðru olmalý.";
//}
//
//// **TEST 2:** Kullanýcý kayýt testi
//TEST_F(UserAuthenticationTest, RegisterUserReturnsTrueForValidDetails) {
//    testing::internal::CaptureStdout(); // Çýktýyý yakalamak için
//    bool result = auth.registerUser("newuser", "newpassword");
//    std::string output = testing::internal::GetCapturedStdout();
//
//    EXPECT_TRUE(result) << "Geçerli kullanýcý adý ve þifre ile kayýt baþarýlý olmalý.";
//    EXPECT_NE(output.find("Registering user: newuser"), std::string::npos)
//        << "Kayýt mesajý doðru olmalý.";
//}
//
//// **TEST 3:** Misafir modu testi
//TEST_F(UserAuthenticationTest, GuestModeOutputsCorrectMessage) {
//    testing::internal::CaptureStdout(); // Çýktýyý yakalamak için
//    auth.guestMode();
//    std::string output = testing::internal::GetCapturedStdout();
//
//    EXPECT_NE(output.find("Entering guest mode..."), std::string::npos)
//        << "Misafir modu mesajý doðru olmalý.";
//}
