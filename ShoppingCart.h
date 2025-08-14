#ifndef SHOPPINGCART_H_INCLUDE
#define SHOPPINGCART_H_INCLUDE
#include <iostream>
#include <vector>
#include "SessionManager.h"
#include "Student.h"
#include "Reservation.h"
#include "Transaction.h"
using namespace std;

class ShoppingCart
{
private:
    static int nextID;
    vector<Reservation> reservations;

public:
    int ID;
    ShoppingCart();
    void addReservation(Reservation);
    void removeReservation(int);
    void viewShoppingCartItems();
    void clear();
    vector<Reservation> getReservations() const;
    Transaction confirm();
};

int ShoppingCart::nextID = 0;

#endif