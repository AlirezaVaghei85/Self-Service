#include <iostream>
#include <ctime>
#include <vector>
#include <string.h>
using namespace std;

class Meal
{
private:
    int meal_id;
    string name;
    float price;
    enum meal_type
    {
        Breakefast,
        Lunch,
        Dinner
    };
    meal_type meal;
    vector<meal_type> side_items;

public:
    Meal();
    void print();
    bool cancel();

    int getMeal_id() { return meal_id; }
    string getName() { return name; }
    float getPrice() { return price; }

    void setMeal_id(int);
    void setName(string);
    void setPrice(float);
};

void Meal::print()
{
    cout << "\nMeal ID: " << meal_id
         << "\nMeal Name: " << name
         << "\nMeal Price: " << price
         << "\nMeal Type: ";
    switch (meal)
    {
    case Breakefast:
        cout << "Breakefast";
        break;
    case Lunch:
        cout << "Lunch";
        break;
    case Dinner:
        cout << "Dinner";
        break;
    default:
        break;
    }
}

bool Meal::cancel()
{
    cout << "\nMeal Cancelled";
}

class Reservation
{
private:
    int reservation_id;
    Student Student;
    DiningHall dHall;
    Meal meal;
    enum status
    {
        SUCCEESS,
        CANCELLED,
        FAILED
    };
    status res_status;
    time_t created_at;

public:
    Reservation();
    void print();
    bool cancel();

    int getReservation_id() { return reservation_id; }

    void setReservation_id(int i) { reservation_id = i; }
};

void Reservation::print()
{
    cout << "\nReservation ID: " << reservation_id
         << "\nReservation Status: ";
    switch (res_status)
    {
    case SUCCEESS:
        cout << "SUCCEESS";
        break;
    case CANCELLED:
        cout << "CANCELLED";
        break;
    case FAILED:
        cout << "FAILED";
        break;
    default:
        break;
    }
    cout << "\nStudent Information: ";
    Student.print();
    cout << "\nMeal information: ";
    meal.print();
    cout << "\nDining Hall Information: ";
    dHall.print();
}

bool Reservation::cancel()
{
    res_status = CANCELLED;
    cout << "\nReservation Cancelled";
    return true;
}

class Student
{
private:
    int user_id;
    string student_id;
    string name;
    string email;
    float balance;
    bool is_active;

public:
    Student();
    void print();
    void reserve_meal(Meal);
    bool cancel_reservation(Reservation);

    int getUser_id() { return user_id; }
    string getStudent_id() { return student_id; }
    string getName() { return name; }
    string getEmail() { return email; }
    float getBalance() { return balance; }

    void setUser_id(int);
    void setStudent_id(string);
    void setName(string n) { name = n; }
    void setEmail(char[]);
    void setBalance(float b) { balance = b; }
};

void Student::print()
{
    cout << "\nUser ID:" << user_id
         << "\nStudent ID: " << student_id
         << "\nName: " << name
         << "\nEmail: " << email
         << "\nBalance: " << balance
         << "\nActivate: " << is_active;
}

void Student::reserve_meal(Meal M)
{
    balance -= M.getPrice();
}

bool Student::cancel_reservation(Reservation R)
{
    Meal M = R.getMeal();
    balance += M.getPrice();

    R.cancel();
}

void Student::setEmail(char e[])
{
    char *p;
    p = strstr(e, "@gamil.com");
    if (p = "@gmail.com")
    {
        email = e;
    }
}

class DiningHall
{
private:
    int hall_id;
    string name;
    string address;
    int capacity;

private:
    DiningHall();
    void print();

    int getHall_id();
    string getName();
    string getAddress();
    int getCapacity();

    void setHall_id(int);
    void setName(string);
    void setAddress(string);
    void setCapacity(int);
};

int main()
{
    return 0;
}
