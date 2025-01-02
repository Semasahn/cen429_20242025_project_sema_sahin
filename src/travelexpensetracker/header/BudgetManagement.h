#ifndef BUDGET_MANAGEMENT_H
#define BUDGET_MANAGEMENT_H

class BudgetManagement {
private:
    double budget = 0.0;

    // Opak d�ng�: Tersine m�hendislik zorla�t�r�c�
    void performOpaqueLoop() const;

public:
    void setBudget(double amount);
    double viewBudget() const;
    void editBudget(double newAmount);
};

#endif // BUDGET_MANAGEMENT_H
