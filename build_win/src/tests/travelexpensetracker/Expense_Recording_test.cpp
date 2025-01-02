#include "ExpenseRecording.h"
#include <gtest/gtest.h>

TEST(ExpenseRecordingTest, LogExpense) {
    ExpenseRecording recorder;
    recorder.logExpense("Food", 25.0);
    auto expenses = recorder.getExpenses();

    ASSERT_EQ(expenses.size(), 1);
    EXPECT_EQ(recorder.encryptDecrypt(expenses[0].first, 'K'), "Food"); // Þifre çözerek doðrula
    EXPECT_EQ(expenses[0].second, 25.0);
}

TEST(ExpenseRecordingTest, CalculateTotalExpenses) {
    ExpenseRecording recorder;
    recorder.logExpense("Food", 25.0);
    recorder.logExpense("Transport", 10.0);
    EXPECT_EQ(recorder.calculateTotalExpenses(), 35.0);
}

TEST(ExpenseRecordingTest, EncryptDecrypt) {
    ExpenseRecording recorder;
    std::string original = "Test";
    std::string encrypted = recorder.encryptDecrypt(original, 'K');
    EXPECT_NE(original, encrypted);
    EXPECT_EQ(recorder.encryptDecrypt(encrypted, 'K'), original); // Þifre çöz
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
