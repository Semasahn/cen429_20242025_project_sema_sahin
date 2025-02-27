#ifndef TRAVELEXPENSETRACKERAPP_H
#define TRAVELEXPENSETRACKERAPP_H

#include "UserAuthentication.h"
#include "TripPlanning.h"
#include "ExpenseRecording.h"
#include "BudgetManagement.h"
#include "SummaryReport.h"

class TravelExpenseTrackerApp {
 public:
  static int main();

 private:
  UserAuthentication auth;
  TripPlanning planner;
  ExpenseRecording recorder;
  BudgetManagement budgetManager;
  SummaryReport reporter;
};

#endif