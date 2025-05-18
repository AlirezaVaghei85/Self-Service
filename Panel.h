#ifndef PANEL_H_INCLUDE
#define PANEL_H_INCLUDE
#include <iostream>
#include "Reservation.h"
using namespace std;

class Panel
{
public:
    void Action(int);
    void showMenu();
    void showStudentInfo();
    void checkBalance();
    void viewReservations();
    void addToShoppingCart();
    void confirmShoppingCart();
    void removeShoppingCartItem();
    void increaseBalance();
    void viewRecentTransactions();
    void cancelReservation(int);
    void exit();
};

#endif