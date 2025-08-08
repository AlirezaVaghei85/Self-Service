#ifndef PANEL_H_INCLUDE
#define PANEL_H_INCLUDE
#include <iostream>
#include <vector>
#include "Student.h"
#include "Reservation.h"
#include "ShoppingCart.h"
#include "SessionManager.h"
using namespace std;

class Panel
{
private:
    StudentSession::SessionManager &CurrentSession = StudentSession::SessionManager::instance();
    Student student;
    vector<Reservation *> reserves;
    ShoppingCart shoppingcart;

public:
    Panel();
    void Action(int);
    void showMenu();
    void showStudentInfo();
    void checkBalance();
    void viewReservations();
    void viewShoppingCart();
    void addToShoppingCart() {}
    void confirmShoppingCart() {}
    void removeShoppingCartItem();
    void increaseBalance();
    void viewRecentTransactions() {}
    void cancelReservation(int) {}
    void exit() {}
};

#endif