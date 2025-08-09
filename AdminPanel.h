#ifndef ADMINPANEL_H_INCLUDE
#define ADMINPANEL_H_INCLUDE
#include <iostream>
using namespace std;

class AdminPanel
{
    void chooseCsvFile(fs::path) {}
    void displayAllMeals() {}
    void displayAllDininigHalls() {}
    void addNewMealIntractive() {}
    void addNewDiningHallIntractive() {}
    void removeMeal(int) {}
    void mealAcitvation(int, bool) {}
    void removeDiningHall(int) {}
    void showMenu() {}
    void action(int) {}
}

#endif