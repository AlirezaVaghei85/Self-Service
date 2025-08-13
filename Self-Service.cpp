#include <iostream>
#include <vector>
#include <string.h>
#include <ctime>
#include <fstream>
#include <filesystem>
#include "SessionManager.h"
#include "SessionBase.h"
#include "ConfigPaths.h"
#include "Storage.h"
#include "Panel.h"
#include "AdminPanel.h"
#include "User.h"
#include "Admin.h"
#include "Student.h"
#include "Reservation.h"
#include "DiningHall.h"
#include "Meal.h"
#include "ShoppingCart.h"
#include "Transaction.h"
using namespace std;
namespace fs = std::filesystem;

class Storage;
class Panel;
class User;
class Admin;
class Student;
class DiningHall;
class Reservation;
class Meal;

void AdminSession::SessionManager::sign_in()
{
    string name;
    string lastname;
    string email;
    string password;

    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Last Name: ";
    cin >> lastname;
    cout << "Enter Email: ";
    cin >> email;
    cout << "Enter Password: ";
    cin >> password;
    ofstream fs("sessions/admins/admins.csv", ios::out | ios::app);
    if (fs.is_open())
    {
        fs << name << lastname << email << password;
    }
    else
    {
        ofstream log("logfile.log", ios::out | ios::app);
        log << "Error! Can not open the sessions/admins/admins.csv file";
        log.close();
    }
}

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

    ifstream fs("studentsCsvFile.csv", ios::in);
    if (fs.is_open())
    {
        line = " ";
        getline(fs, line);

        while (getline(fs, line) || !Is_Found)
        {
            fs >> userID;

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
                }
                else
                    break;
            }
        }
        if (Is_Found)
        {
            cout << "Login Successful!" << endl;
            currentStudent.setUser_id(userID);
            currentStudent.setStudentID(studentID);
            currentStudent.setName(name);
            currentStudent.setPhone(phone);
            currentStudent.setEmail(email.c_str());
            currentStudent.activate();
        }
        else
        {
            cout << "Error! Email or Password is incorrect." << endl;
        }
        fs.close();
    }
    else
    {
        ofstream log("logfile.log", ios::out | ios::app);
        log << "Error! Can not open the studentsCsvFile.csv";
        log.close();
    }
}

void StudentSession::SessionManager::save_session()
{
    string name = currentStudent.getStudentID();
    name.append(".txt");
    string dir = "sessions/students/transactions/";
    dir.append(name);
    cout << dir << endl;
    ofstream fs(dir, ios::out | ios::trunc);

    if (fs.is_open())
    {
        // fs <<
    }
    else
    {
        ofstream log("logfile.log", ios::out | ios::app);
        log << "Cannot open the " << dir << " file!";
        log.close();
    }
}

fs::path ConfigPaths::j_reservations(Student *student)
{
    string name = student->getStudentID();
    name.append(".json");
    string dir = "sessions/students/reservations/";
    dir.append(name);
    if (!fs::exists(dir))
    {
        fs::create_directories(dir);
    }
    return fs::path(dir);
}

fs::path ConfigPaths::t_transactions(Student *student)
{
    string name = student->getStudentID();
    name.append(".txt");
    string dir = t_student_transactions.string();
    dir.append(name);
    if (!fs::exists(dir))
    {
        fs::create_directories(dir);
    }
    return fs::path(dir);
}

void Storage::displayAllMeals()
{
    for (Meal &meal : allMeals)
    {
        meal.print();
    }
}

void Storage::displayAllDininigHalls()
{
    for (DiningHall &hall : allDiningHalls)
    {
        hall.print();
    }
}

void Storage::addMeal(Meal meal)
{
    meal.setMeal_id(mealIDCounter++);
    allMeals.push_back(meal);
}

void Storage::addDiningHall(DiningHall dhall)
{
    dhall.setHall_id(diningHallIDCounter++);
    allDiningHalls.push_back(dhall);
}

void Storage::removeMeal(int mealID)
{
    for (int i = 0; i < allMeals.size(); i++)
    {
        if (allMeals[i].getMeal_id() == mealID)
        {
            allMeals.erase(allMeals.begin() + i);
        }
    }
}

void Storage::removeDiningHall(int hallID)
{
    for (int i = 0; i < allDiningHalls.size(); i++)
    {
        if (allDiningHalls[i].getHall_id() == hallID)
        {
            allDiningHalls.erase(allDiningHalls.begin() + i);
        }
    }
}

void Storage::MealActivation(int mealID, bool activate)
{
    vector<Meal>::iterator it = findMeal(mealID);
    if (activate)
        it->activate();
    else
        it->deactivate();
}

vector<Meal>::iterator Storage::findMeal(int mealID)
{
    vector<Meal>::iterator meal;

    for (meal = allMeals.begin(); meal == allMeals.end() - 1; ++meal)
    {
        if (meal->getMeal_id() == mealID)
        {
            return meal;
            break;
        }
    }
}

vector<DiningHall>::iterator Storage::findDiningHall(int hallID)
{
    vector<DiningHall>::iterator DHall;

    for (DHall = allDiningHalls.begin(); DHall == allDiningHalls.end() - 1; ++DHall)
    {
        if (DHall->getHall_id() == hallID)
        {
            return DHall;
            break;
        }
    }
}

Panel::Panel()
{
    student = CurrentStudent.getCurrentStudent();
    reserves = student.getReserves();
    // for (int i = 0; i < student.getReserves().size(); i++)
    // {
    //     reserves[i] = student.getReserves()[i];
    // }
}

void Panel::showMenu()
{
    system("cls");
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

void AdminPanel::showMenu()
{
    system("cls");
    cout << "\n1.Choose Csv File."
         << "\n2.Display All Meals."
         << "\n3.Display All DininigHalls"
         << "\n4.Add New Meal Intractive"
         << "\n5.Add New DiningHall Intractive"
         << "\n6.Remove Meal"
         << "\n7.Meal Acitvation"
         << "\n8.Remove DiningHall";
}

void AdminPanel::action(int key)
{
    int x;
    fs::path directorypath;
    switch (key)
    {
    case 1:
        cout << "Enter The Csv File Path: ";
        cin >> directorypath;
        chooseCsvFile(directorypath);
        break;
    case 2:
        displayAllMeals();
        break;
    case 3:
        displayAllDininigHalls();
        break;
    case 4:
        addNewMealIntractive();
        break;
    case 5:
        addNewDiningHallIntractive();
        break;
    case 6:
        cout << "Enter The Meal ID: ";
        cin >> x;
        removeMeal(x);
        break;
    case 7:
        cout << "Enter The Meal ID: ";
        cin >> x;
        cout << "Choose One:(True/False) ";
        bool answer;
        cin >> answer;
        mealAcitvation(x, answer);
        break;
    case 8:
        cout << "Enter The Dining Hall ID: ";
        cin >> x;
        removeDiningHall(x);
        break;
    default:
        break;
    }
}

void AdminPanel::chooseCsvFile(fs::path path)
{
    if (fs::exists(path))
    {
        cout << "File exists: " << path << endl;
    }
    else
    {
        cout << "File does not exist, creating directory..." << endl;
        fs::create_directory(path);
    }

    ofstream fs(path / "admin.csv", ios::out | ios::app);
    if (fs.is_open())
    {
        cout << "CSV file opened successfully." << endl;
        fs.close();
    }
    else
    {
        ofstream log("logfile.log", ios::out | ios::app);
        log << "Error! Can not open the sessions/admins/admins.csv file";
        log.close();
    }
}

void AdminPanel::displayAllMeals()
{
    storage.displayAllMeals();
}

void AdminPanel::displayAllDininigHalls()
{
    storage.displayAllDininigHalls();
}

void AdminPanel::addNewMealIntractive()
{
    Meal M;
    string name;
    float price;
    int mealType, reserveDay;

    cout << "Enter Meal Name: ";
    cin >> name;
    M.setName(name);

    cout << "Enter Meal Price: ";
    cin >> price;
    M.setPrice(price);

    cout << "Choose Meal Type (0: Breakfast, 1: Lunch, 2: Dinner): ";
    cin >> mealType;
    M.setMealType(static_cast<MealType>(mealType));

    cout << "Choose Reserve Day (0: Saturday, 1: Sunday, 2: Monday, 3: Tuesday, 4: Wednesday, 5: Thursday, 6: Friday): ";
    cin >> reserveDay;
    M.setResesrveDay(static_cast<ReserveDay>(reserveDay));

    storage.addMeal(M);
}

void AdminPanel::addNewDiningHallIntractive()
{
    DiningHall DH;
    string name, address;
    int capacity;

    cout << "Enter Dining Hall Name: ";
    cin >> name;
    DH.setName(name);

    cout << "Enter Dining Hall Address: ";
    cin >> address;
    DH.setAddress(address);

    cout << "Enter Dining Hall Capacity: ";
    cin >> capacity;
    DH.setCapacity(capacity);

    storage.addDiningHall(DH);
}

void AdminPanel::removeMeal(int mealID)
{
    storage.removeMeal(mealID);
}

void AdminPanel::mealAcitvation(int mealID, bool activate)
{
    storage.MealActivation(mealID, activate);
}

void AdminPanel::removeDiningHall(int hallID)
{
    storage.removeDiningHall(hallID);
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

    StudentSession::SessionManager &S = StudentSession::SessionManager::instance();
    S.login();
    Panel P;
    P.showMenu();
    cout << endl
         << "Choose an option: ";
    int x;
    cin >> x;
    P.Action(x);

    return 0;
}
