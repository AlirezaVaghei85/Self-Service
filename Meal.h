#ifndef MEAL_H_INCLUDE
#define MEAL_H_INCLUDE
#include <iostream>
#include <vector>
using namespace std;

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

class Meal
{
private:
    int mealID;
    string name;
    float price;
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

    int getMeal_id() const { return mealID; }
    string getName() const { return name; }
    float getPrice() const { return price; }
    MealType getMealType() const { return mealType; }
    ReserveDay getReserveDay() const { return reserveday; }

    void setMeal_id(int i) { mealID = i; }
    void setName(string n) { name = n; }
    void setPrice(float p) { price = p; }
    void setMealType(MealType m) { mealType = m; }
    void setResesrveDay(ReserveDay r) { reserveday = r; }
};

#endif