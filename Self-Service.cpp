#include <iostream>
#include <ctime>
#include <vector>
#include <string.h>
using namespace std;

class User;
class Admin;
class Student;
class DiningHall;
class Reservation;
class Meal;

class User
{
private:
    int userID;
    string name;
    string lastName;
    string hashedPassword;

public:
    virtual void print() const;
    virtual void getType();

    int getUserID() { return userID; }
    string getName() { return name; }
    string getLastName() { return lastName; }
    string getHashedPassword() { return hashedPassword; }

    void setUserID(int i) { userID = i; }
    void setName(string n) { name = n; }
    void setLastName(string n) { lastName = n; }
    void setHashedPassword(string h) { hashedPassword = h; }
};

class Admin : public User
{
private:
public:
};

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

    void setMeal_id(int i) { meal_id = i; }
    void setName(string n) { name = n; }
    void setPrice(float p) { price = p; }
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

class DiningHall
{
private:
    int hall_id;
    string name;
    string address;
    int capacity;

public:
    DiningHall();
    void print();

    int getHall_id() { return hall_id; }
    string getName() { return name; }
    string getAddress() { return address; }
    int getCapacity() { return capacity; }

    void setHall_id(int i) { hall_id = i; }
    void setName(string n) { name = n; }
    void setAddress(string a) { address = a; }
    void setCapacity(int c) { capacity = c; }
};

void DiningHall::print()
{
    cout << "\nDining Hall ID: " << hall_id
         << "\nDining Hall Name: " << name
         << "\nDining Hall Address: " << address
         << "\nDining Hall Capacity: " << capacity;
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
    bool cancel_reservation(Reservation *);

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

bool Student::cancel_reservation(Reservation *R)
{
    Meal M = R->getMeal();
    balance += M.getPrice();

    R->cancel();
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
    Meal getMeal() { return meal; }

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

int main()
{
    return 0;
}
