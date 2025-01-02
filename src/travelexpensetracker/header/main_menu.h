// main_menu.h
#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <iostream>
#include <string>

class MainMenu {
 public:
  void displayMenu();
  void handleUserSelection();
  void registerUser();
  void loginUser();
  void recordExpense();
  void generateSummary();
  void planTrip();
};

#endif // MAIN_MENU_H
