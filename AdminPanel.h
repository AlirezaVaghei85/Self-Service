#ifndef ADMINPANEL_H_INCLUDE
#define ADMINPANEL_H_INCLUDE
#include <iostream>
// #include <filesystem>
#include "Storage.h"
using namespace std;
// namespace fs = std::filesystem;

class AdminPanel
{
private:
    Storage &storage = Storage::instance();

public:
    // void chooseCsvFile(fs::path) {}
    void displayAllMeals() {}
    void displayAllDininigHalls() {}
    void addNewMealIntractive() {}
    void addNewDiningHallIntractive() {}
    void removeMeal(int) {}
    void mealAcitvation(int, bool) {}
    void removeDiningHall(int) {}
    void showMenu();
    void action(int);
}

#endif