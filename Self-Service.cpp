#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

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

    int getUser_id();
    string getStudent_id();
    string getName();
    string getEmail();
    float getBalance();

    void setUser_id(int);
    void setStudent_id(string);
    void setName(string);
    void setEmail(string);
    void setBalance(float);
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
    time_t created_at;

public:
    Reservation();
    void print();
    bool cancel();

    int getReservation_id();

    void setReservation_id(int);
};

class Meal
{
private:
    int meal_id;
    string name;
    float price;
    enum meal_type
    {
    };
    vector<meal_type> side_items = {};

public:
    Meal();
    void print();
    bool cancel();

    int getMeal_id();
    string getName();
    float getPrice();

    void setMeal_id(int);
    void setName(string);
    void setPrice(float);
};

class DiningHall
{
};

int main()
{
    return 0;
}
