#ifndef STORAGE_H_INCLUDE
#define STORAGE_H_INCLUDE
#include <iostream>
#include <vector>
#include "Meal.h"
#include "DiningHall.h"
using namespace std;

class Storage
{
private:
    int mealIDCounter = 0;
    int diningHallIDCounter = 0;
    vector<Meal> allMeals;
    vector<DiningHall> allDiningHalls;

    Storage() = default;

public:
    void displayAllMeals();
    void displayAllDininigHalls();
    void addMeal(Meal);
    void addDiningHall(DiningHall);
    void removeMeal(int);
    void removeDiningHall(int);
    void MealActivation(int, bool);
    vector<Meal>::iterator findMeal(int);
    vector<DiningHall>::iterator findDiningHall(int);
    static Storage &instance()
    {
        static Storage instance;
        return instance;
    }

    Storage(const Storage &) = delete;
    Storage operator=(const Storage &) = delete;
};

#endif