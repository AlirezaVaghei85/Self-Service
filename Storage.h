#ifndef STORAGE_H_INCLUDE
#define STORAGE_H_INCLUDE
#include <iostream>
#include "Meal.h"
#include "DiningHall.h"
using namespace std;

class Storage
{
private:
    int mealIDCounter;
    int diningHallIDCounter;
    vector<Meal> allMeals;
    vector<DiningHall> allDiningHalls;

    Storage() = default;

public:
    void displayAllMeals();
    void displayAllDininigHalls();
    void addMeal(Meal);
    void addDinningHall(DinningHall);
    void removeMeal(int);
    void removeDinningHall(int);
    void MealActivation(int, bool);
    vector<Meal>::iterator findMeal(int);
    vector<DinningHall>::iterator findDiningHall(int);
    static Storage &instance()
    {
        static Storage instance;
        return instance;
    }

    Storage(const Storage &) = delete;
    Storage operator=(const Storage &) = delete;
};

#endif