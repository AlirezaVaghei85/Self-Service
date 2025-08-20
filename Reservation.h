#ifndef RESERVATION_H_INCLUDE
#define RESERVATION_H_INCLUDE
#include <iostream>
#include "Student.h"
#include "DiningHall.h"
#include "Meal.h"
using namespace std;

class Student;
class DiningHall;
class Reservation;
class Meal;

enum RStatus
{
    Success,
    Cancelled,
    Failed
};

class Reservation
{
private:
    int reservationID;
    Student *student;
    DiningHall dHall;
    Meal meal;
    RStatus status;
    time_t createdAT;

public:
    Reservation() {}
    Reservation(int ID, Student *S, Meal M, DiningHall DH, RStatus RST);
    void print() const;
    bool cancel();

    int getReservation_id() const { return reservationID; }
    RStatus getStatus() const { return status; }
    Meal getMeal() const { return meal; }
    DiningHall getDiningHall() const { return dHall; }

    void setReservation_id(int i) { reservationID = i; }
    void setStatus(RStatus R) { status = R; }
    void setStudent(Student *S) { student = S; }
    void setMeal(Meal M) { meal = M; }
    void setDiningHall(DiningHall DH) { dHall = DH; }
};

#endif