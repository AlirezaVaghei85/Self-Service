#ifndef RESERVATION_H_INCLUDE
#define RESERVATION_H_INCLUDE
#include <iostream>
#include "Student.h"
#include "DiningHall.h"
#include "Meal.h"
using namespace std;

enum RStatus
{
    SUCCEESS,
    CANCELLED,
    FAILED
};

class Reservation
{
private:
    int reservationID;
    Student *Student;
    DiningHall *dHall;
    Meal *meal;
    RStatus status;
    time_t createdAT;

public:
    Reservation();
    void print() const;
    bool cancel();

    int getReservation_id() { return reservationID; }
    Meal getMeal() { return *meal; }
    RStatus getStatus() { return status; }

    void setReservation_id(int i) { reservationID = i; }
    void setStatus(RStatus R) { status = R; }
};

#endif