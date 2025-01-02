#ifndef TRAVELEXPENSETRACKERAPP_H
#define TRAVELEXPENSETRACKERAPP_H

#include "UserAuthentication.h"
#include "TripPlanning.h"
#include "ExpenseRecording.h"
#include "BudgetManagement.h"
#include "SummaryReport.h"

class TravelExpenseTrackerApp {
 public:
  void run();

  // Getter functions for testing purposes
  UserAuthentication& getAuth() { return auth; }
  TripPlanning& getPlanner() { return planner; }
  ExpenseRecording& getRecorder() { return recorder; }
  BudgetManagement& getBudgetManager() { return budgetManager; }
  SummaryReport& getReporter() { return reporter; }

 private:
  UserAuthentication auth;
  TripPlanning planner;
  ExpenseRecording recorder;
  BudgetManagement budgetManager;
  SummaryReport reporter;
};

#endif
