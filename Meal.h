#ifndef MEAL_H_INCLUDE
#define MEAL_H_INCLUDE
#include <iostream>
#include <vector>
using namespace std;

class Meal
{
private:
    int mealID;
    string name;
    float price;
    enum MealType
    {
        Breakefast,
        Lunch,
        Dinner
    };
    enum ReserveDay
    {
        Saturday,
        Sunday,
        Monday,
        Tueseday,
        Wednesday,
        Thursday,
        Friday
    };
    ReserveDay reserveday;
    bool isActive;
    MealType mealType;
    vector<string> sideItems;

public:
    Meal() {}
    void print();
    bool cancel();
    bool isActivate() { return isActive; }
    void activate() { isActive = true; }
    void deactivate() { isActive = false; }
    void addSideItem(string s) { sideItems.push_back(s); }
    void addPrice(float p) { setPrice(price + p); }

    int getMeal_id() { return mealID; }
    string getName() { return name; }
    float getPrice() { return price; }
    MealType getMealType() { return mealType; }
    ReserveDay getReserveDay() { return reserveday; }

    void setMeal_id(int i) { mealID = i; }
    void setName(string n) { name = n; }
    void setPrice(float p) { price = p; }
    void setMealType(MealType m) { mealType = m; }
    void setResesrveDay(ReserveDay r) { reserveday = r; }
};

#endif