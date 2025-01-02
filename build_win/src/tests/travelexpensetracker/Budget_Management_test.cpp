//#include "BudgetManagement.h"
//#include <gtest/gtest.h>
//
//// Test: Bütçe Ayarlama
//TEST(BudgetManagementTest, SetBudget) {
//    BudgetManagement manager;
//    manager.setBudget(500.0);
//    EXPECT_DOUBLE_EQ(manager.viewBudget(), 500.0);
//}
//
//// Test: Negatif Bütçe Ayarlama
//TEST(BudgetManagementTest, SetNegativeBudget) {
//    BudgetManagement manager;
//    manager.setBudget(-100.0);
//    EXPECT_DOUBLE_EQ(manager.viewBudget(), 0.0); // Negatif bütçe ayarlanmaz, varsayýlan kalýr
//}
//
//// Test: Bütçe Düzenleme
//TEST(BudgetManagementTest, EditBudget) {
//    BudgetManagement manager;
//    manager.setBudget(1000.0);
//    manager.editBudget(1500.0);
//    EXPECT_DOUBLE_EQ(manager.viewBudget(), 1500.0);
//}
//
//// Test: Negatif Bütçe Düzenleme
//TEST(BudgetManagementTest, EditNegativeBudget) {
//    BudgetManagement manager;
//    manager.setBudget(1000.0);
//    manager.editBudget(-200.0);
//    EXPECT_DOUBLE_EQ(manager.viewBudget(), 1000.0); // Negatif deðerle düzenlenemez
//}
