#ifndef PANEL_H_INCLUDE
#define PANEL_H_INCLUDE
#include <iostream>
#include <vector>
#include "Student.h"
#include "Reservation.h"
#include "ShoppingCart.h"
using namespace std;

class Panel
{
private:
    Student *student;
    vector<Reservation *> reserves;
    ShoppingCart *shoppingcart;

public:
    void Action(int);
    void showMenu();
    void showStudentInfo();
    void checkBalance();
    void viewReservations();
    void viewShoppingCart();
    void addToShoppingCart();
    void confirmShoppingCart();
    void removeShoppingCartItem();
    void increaseBalance();
    void viewRecentTransactions();
    void cancelReservation(int);
    void exit();
};

#endif