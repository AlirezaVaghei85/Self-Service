#include <iostream>
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
    bool cancel_reservation(Rezervation);

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

class Rezervation
{
};

class Meal
{
};

class DiningHall
{
};

int main()
{
    return 0;
}
