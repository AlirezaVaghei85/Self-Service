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

    static Storage &instance();
    Storage() = default;

public:
    Storage(const Storage &) = delete;
    Storage operator=(const Storage &) = delete;
};

#endif