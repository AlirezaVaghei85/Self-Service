#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

class Meal
{
private:
    int meal_id;
    string name;
    float price;
    enum meal_type
    {
        chicken_rice,
        kebab,
        pizza
    };
    vector<meal_type> side_items =
        {

    };

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
    Meal getMeal();

    void setReservation_id(int);
};

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
