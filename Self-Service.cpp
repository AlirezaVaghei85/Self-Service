#include <iostream>
#include <vector>
#include <string.h>
#include "SessionBase.h"
#include "Storage.h"
#include "Panel.h"
#include "User.h"
#include "Admin.h"
#include "Student.h"
#include "Reservation.h"
#include "DiningHall.h"
#include "Meal.h"
#include "ShoppingCart.h"
#include "Transaction.h"
using namespace std;
using namespace StudentSession;

class Storage;
class Panel;
class User;
class Admin;
class Student;
class DiningHall;
class Reservation;
class Meal;

namespace AdminSession
{
    class SessionManager : public SessionBase
    {
    private:
        Admin *currentAdmin;
        int adminID;

        static SessionManager &instance();

    public:
        Admin currentAdmin();
        void load_session() override;
        void save_session() override;
        void login(string, string) override;
        void logout() override;

        Admin getcurrentAdmin() { return *currentAdmin; }
        int getAdminID() { return adminID; }
    };
}
namespace StudentSession
{
    class SessionManager : public SessionBase
    {
    private:
        Student *currentStudent;
        ShoppingCart *shopping_cart;
        int studentID;

        static SessionManager &instance();

    public:
        Student currentStudent();
        ShoppingCart shoppingCart();
        void load_session() override;
        void save_session() override;
        void login(string, string) override;
        void logout() override;

        Student getCurrentStudent() { return *currentStudent; }
        ShoppingCart getShoppingCart() { return *shopping_cart; }
    };
}

void Panel::showMenu()
{
    cout << "\n1. Show Student Info."
         << "\n2. Check Balance."
         << "\n3. View Reservations."
         << "\n4. Add To Shopping Cart."
         << "\n5. Remove Shopping Cart Item."
         << "\n6. Increase Balance."
         << "\n7. View Recent Transactions."
         << "\n8. Cancel Reservation."
         << "\n9. Exit.";
}

void Panel::Action(int key)
{
    switch (key)
    {
    case 1:
        showStudentInfo();
        break;
    case 2:
        checkBalance();
        break;
    case 3:
        viewReservations();
        break;
    case 4:
        addToShoppingCart();
        break;
    case 5:
        removeShoppingCartItem();
        break;
    case 6:
        increaseBalance();
        break;
    case 7:
        viewRecentTransactions();
        break;
    case 8:
        int i;
        cancelReservation(i);
        break;
    case 9:
        exit();
        break;
    default:
        break;
    }
}

void Panel::showStudentInfo()
{
    student->print();
}

void Panel::checkBalance()
{
    cout << "Balance: " << student->getBalance();
}

void Panel::viewReservations()
{
    for (Reservation *R : reserves)
    {
        R->print();
    }
}

void Panel::viewShoppingCart()
{
    shoppingcart->viewShoppingCartItems();
}

void User::print() const
{
    cout << "\nUSER ID: " << userID
         << "\nName: " << name
         << "\nLast Name: " << lastName
         << "\nHashed Password: " << hashedPassword;
}

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

void DiningHall::print()
{
    cout << "\nDining Hall ID: " << hallID
         << "\nDining Hall Name: " << name
         << "\nDining Hall Address: " << address
         << "\nDining Hall Capacity: " << capacity;
}

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

void Reservation::print() const
{
    cout << "\nReservation ID: " << reservationID
         << "\nReservation Status: ";
    switch (status)
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
    Student->print();
    cout << "\nMeal information: ";
    meal->print();
    cout << "\nDining Hall Information: ";
    dHall->print();
}

bool Reservation::cancel()
{
    status = CANCELLED;
    cout << "\nReservation Cancelled";
    return true;
}

void ShoppingCart::addReservation(Reservation reservation)
{
    reservations.push_back(reservation);
}

void ShoppingCart::removeReservation(int ID)
{
    reservations.erase(reservations.begin() + ID);
}

void ShoppingCart::viewShoppingCartItems()
{
    for (int i = 0; i < reservations.size(); i++)
    {
        reservations[i].print();
    }
}

void ShoppingCart::clear()
{
    reservations.clear();
}

vector<Reservation> ShoppingCart::getReservations() const
{
    return reservations;
}

int GetInteger() // تابعی برای گرفتن فقظ مقادیر عددی
{
    char x;
    int a = 0;

    while (x != 10)
    {
        x = getchar();
        if (x >= '0' && x <= '9')
            a = (a * 10) + (x - 48);
    }
    return a;
}

int main()
{
    return 0;
}
