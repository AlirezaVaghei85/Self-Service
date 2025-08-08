#include <iostream>
#include <vector>
#include <string.h>
#include <ctime>
#include <fstream>
#include "SessionManager.h"
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

class Storage;
class Panel;
class User;
class Admin;
class Student;
class DiningHall;
class Reservation;
class Meal;

void StudentSession::SessionManager::login()
{
    string line;
    int location;
    int userID;
    string studentID;
    string name;
    string lastname;
    string password;
    string email;
    string phone;
    string Entered_Email;
    string Entered_Password;
    bool Is_Found = false;

    cout << "Login" << endl
         << "Enter Your Email Address: ";
    cin >> Entered_Email;

    ifstream fp("studentsCsvFile.csv", ios::in);
    if (fp.is_open())
    {
        line = "";
        getline(fp, line);

        while (getline(fp, line) || !Is_Found)
        {
            fp >> userID;

            location = line.find(",");
            line = line.substr(location + 1, line.length());
            location = line.find(",");
            studentID = line.substr(0, location);

            line = line.substr(location + 1, line.length());
            location = line.find(",");
            name = line.substr(0, location);

            line = line.substr(location + 1, line.length());
            location = line.find(",");
            lastname = line.substr(0, location);

            line = line.substr(location + 1, line.length());
            location = line.find(",");
            password = line.substr(0, location);

            line = line.substr(location + 1, line.length());
            location = line.find(",");
            email = line.substr(0, location);

            line = line.substr(location + 1, line.length());
            location = line.find(",");
            phone = line.substr(0, location);

            if (Entered_Email == email)
            {
                cout << "Enter Your Password: ";
                cin >> Entered_Password;
                if (Entered_Password == password)
                {
                    Is_Found = true;
                    // *this->load_session();
                }
                else
                    break;
            }
        }
        if (Is_Found)
        {
            cout << "Login Successful!" << endl;
            currentStudent->setUser_id(userID);
            currentStudent->setStudentID(studentID);
            currentStudent->setName(name);
            currentStudent->setPhone(phone);
            currentStudent->setEmail(email.c_str());
            currentStudent->activate();
        }
        else
        {
            cout << "Error! Email or Password is incorrect." << endl;
        }
        fp.close();
    }
    else
    {
        system("cls");
        cout << "Error! Can not open the studentsCsvFile.csv";
    }
}

Panel::Panel()
{
    student = CurrentSession.getCurrentStudent();
    shoppingcart = CurrentSession.getShoppingCart();
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
        cout << "Choose a Reservatoin: " << endl;
        viewReservations();
        int i;
        cin >> i;
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
    student.print();
}

void Panel::checkBalance()
{
    cout << "Balance: " << student.getBalance();
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
    shoppingcart.viewShoppingCartItems();
}

void Panel::removeShoppingCartItem()
{
    int i;
    cout << "Enter Reservation ID: ";
    cin >> i;
    shoppingcart.removeReservation(i);
}

void Panel::increaseBalance()
{
    float i;
    cout << "Enter The Balance You Need To Increase: ";
    cin >> i;
    student.setBalance(student.getBalance() + i);
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
    return true;
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
    return true;
}

void Student::setEmail(string Entered_Email)
{
    int location = Entered_Email.find("@");
    string check_email = Entered_Email.substr(location, Entered_Email.length());
    if (check_email == "@gmail.com" || check_email == "@yahoo.com")
    {
        email = Entered_Email;
    }
    else
        cout << "INVALID EMAIL!";
}

Reservation::Reservation(int ID, Student *S, Meal *M, DiningHall *DH, RStatus RST)
{
    setReservation_id(ID);
    student = S;
    meal = M;
    dHall = DH;
    status = RST;
}

void Reservation::print() const
{
    cout << "\nReservation ID: " << reservationID
         << "\nReservation Status: ";
    switch (status)
    {
    case Success:
        cout << "SUCCEESS";
        break;
    case Cancelled:
        cout << "CANCELLED";
        break;
    case Failed:
        cout << "FAILED";
        break;
    default:
        break;
    }
    cout << "\nStudent Information: ";
    student->print();
    cout << "\nMeal information: ";
    meal->print();
    cout << "\nDining Hall Information: ";
    dHall->print();
}

bool Reservation::cancel()
{
    status = Cancelled;
    cout << "\nReservation Cancelled";
    return true;
}

ShoppingCart::ShoppingCart()
{
    ID = ++nextID;
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
    int size = reservations.size();
    for (int i = 0; i < size; i++)
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

Transaction ShoppingCart::confirm()
{
    Transaction Trans;
    Trans.setStatus(PENDING);
    Trans.setType(PAYMENT);
    float amount = 0;
    for (Reservation R : reservations)
    {
        amount += R.getMeal().getPrice();
    }
    Trans.setAmount(amount);
    time_t currentTime = time(NULL);
    Trans.setTime(currentTime);
    srand(time(0));
    long long int randomNumber = 100000000000 + (rand() % (99999900000000000));
    Trans.setTrackingCode(randomNumber);
    return Trans;
}

Transaction::Transaction()
{
    ID = ++nextID;
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
    system("cls");

    StudentSession::SessionManager S;
    S.login();

    return 0;
}
