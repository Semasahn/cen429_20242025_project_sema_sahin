#include "BudgetManagement.h"
#include <iostream>
#include <thread> // Opak d�ng� i�in zamanlama

// Opak D�ng�: Kodun analiz edilmesini zorla�t�r�r
void BudgetManagement::performOpaqueLoop() const {
    volatile int dummy = 0;
    for (int i = 0; i < 100000; ++i) {
        dummy += (i % 2 == 0) ? i : -i;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // D�ng� i�inde gecikme
}

void BudgetManagement::setBudget(double amount) {
    performOpaqueLoop();
    if (amount < 0) {
        std::cerr << "Error: Budget cannot be negative!" << std::endl;
        return;
    }
    budget = amount;
    std::cout << "Budget set to: " << budget << " USD" << std::endl;
}

double BudgetManagement::viewBudget() const {
    performOpaqueLoop();
    std::cout << "Current budget: " << budget << " USD" << std::endl;
    return budget;
}

void BudgetManagement::editBudget(double newAmount) {
    performOpaqueLoop();
    if (newAmount < 0) {
        std::cerr << "Error: New budget cannot be negative!" << std::endl;
        return;
    }
    budget = newAmount;
    std::cout << "Budget updated to: " << budget << " USD" << std::endl;
}
