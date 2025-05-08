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

void User::print() const
{
    cout << "\nUSER ID: " << userID
         << "\nName: " << name
         << "\nLast Name: " << lastName
         << "\nHashed Password: " << hashedPassword;
}

class Admin : public User
{
private:
public:
    void print() const;
    void getType();
};

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
    Meal();
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

void Meal::print()
{
    cout << "\nMeal ID: " << mealID
         << "\nMeal Name: " << name
         << "\nMeal Price: " << price
         << "\nMeal Type: ";
    switch (mealType)
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
    int hallID;
    string name;
    string address;
    int capacity;

public:
    DiningHall();
    void print();

    int getHall_id() { return hallID; }
    string getName() { return name; }
    string getAddress() { return address; }
    int getCapacity() { return capacity; }

    void setHall_id(int i) { hallID = i; }
    void setName(string n) { name = n; }
    void setAddress(string a) { address = a; }
    void setCapacity(int c) { capacity = c; }
};

void DiningHall::print()
{
    cout << "\nDining Hall ID: " << hallID
         << "\nDining Hall Name: " << name
         << "\nDining Hall Address: " << address
         << "\nDining Hall Capacity: " << capacity;
}

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
    bool isActive() { return isActive; }
    void activate() { isActive = true; }
    void deactivate() { isActive = false; }
    vector<Reservation> getReserves();

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

void Student::print() const
{
    cout << "\nUser ID:" << user_id
         << "\nStudent ID: " << studentID
         << "\nName: " << name
         << "\nEmail: " << email
         << "\nBalance: " << balance
         << "\nActivate: " << isActive;
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
