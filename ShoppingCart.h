#ifndef SHOPPINGCART_H_INCLUDE
#define SHOPPINGCART_H_INCLUDE
#include <iostream>
#include <vector>
#include "Reservation.h"
using namespace std;

class ShoppingCart
{
private:
    vector<Reservation> reservations;

public:
    void addReservation(Reservation);
    void removeReservation(int);
    void viewShoppingCartItems();
};

#endif