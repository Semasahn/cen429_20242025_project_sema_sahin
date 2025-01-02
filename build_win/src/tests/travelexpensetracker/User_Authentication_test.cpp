//#include "UserAuthentication.h"
//#include "gtest/gtest.h"
//#include <sstream>
//
//// Test s�n�f�
//class UserAuthenticationTest : public ::testing::Test {
//protected:
//    UserAuthentication auth; // Testlerde kullan�lacak UserAuthentication nesnesi
//};
//
//// **TEST 1:** Kullan�c� giri� testi
//TEST_F(UserAuthenticationTest, LoginReturnsTrueForValidCredentials) {
//    testing::internal::CaptureStdout(); // ��kt�y� yakalamak i�in
//    bool result = auth.login("testuser", "password123");
//    std::string output = testing::internal::GetCapturedStdout();
//
//    EXPECT_TRUE(result) << "Ge�erli kullan�c� ad� ve �ifre ile giri� ba�ar�l� olmal�.";
//    EXPECT_NE(output.find("Logging in user: testuser"), std::string::npos)
//        << "Giri� mesaj� do�ru olmal�.";
//}
//
//// **TEST 2:** Kullan�c� kay�t testi
//TEST_F(UserAuthenticationTest, RegisterUserReturnsTrueForValidDetails) {
//    testing::internal::CaptureStdout(); // ��kt�y� yakalamak i�in
//    bool result = auth.registerUser("newuser", "newpassword");
//    std::string output = testing::internal::GetCapturedStdout();
//
//    EXPECT_TRUE(result) << "Ge�erli kullan�c� ad� ve �ifre ile kay�t ba�ar�l� olmal�.";
//    EXPECT_NE(output.find("Registering user: newuser"), std::string::npos)
//        << "Kay�t mesaj� do�ru olmal�.";
//}
//
//// **TEST 3:** Misafir modu testi
//TEST_F(UserAuthenticationTest, GuestModeOutputsCorrectMessage) {
//    testing::internal::CaptureStdout(); // ��kt�y� yakalamak i�in
//    auth.guestMode();
//    std::string output = testing::internal::GetCapturedStdout();
//
//    EXPECT_NE(output.find("Entering guest mode..."), std::string::npos)
//        << "Misafir modu mesaj� do�ru olmal�.";
//}
