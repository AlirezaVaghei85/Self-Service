#ifndef STUDENT_H_INCLUDE
#define STUDENT_H_INCLUDE
#include <iostream>
#include "User.h"
#include "Reservation.h"
using namespace std;

class Student : public User
{
private:
    int user_id;
    string studentID;
    string name;
    string phone;
    string email;
    float balance;
    bool isActive;
    vector<Reservation> reserves;

public:
    Student();
    void print() const;
    void getType();
    void reserve_meal(Meal);
    bool cancel_reservation(Reservation *);
    bool isActivate() { return isActive; }
    void activate() { isActive = true; }
    void deactivate() { isActive = false; }
    vector<Reservation> getReserves() { return reserves; }

    int getUser_id() { return user_id; }
    string getStudentID() { return studentID; }
    string getName() { return name; }
    string getPhone() { return phone; }
    string getEmail() { return email; }
    float getBalance() { return balance; }

    void setUser_id(int);
    void setStudentID(string);
    void setName(string n) { name = n; }
    void setPhone(string p) { phone = p; }
    void setEmail(char[]);
    void setBalance(float b) { balance = b; }
};

#endif