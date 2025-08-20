#ifndef DININGHALL_H_INCLUDE
#define DININGHALL_H_INCLUDE
#include <iostream>
using namespace std;

class DiningHall
{
private:
    int hallID;
    string name;
    string address;
    int capacity;

public:
    DiningHall() {}
    void print() const;

    int getHall_id() const { return hallID; }
    string getName() const { return name; }
    string getAddress() const { return address; }
    int getCapacity() const { return capacity; }

    void setHall_id(int i) { hallID = i; }
    void setName(string n) { name = n; }
    void setAddress(string a) { address = a; }
    void setCapacity(int c) { capacity = (c > 0) ? c : -1 * c; }
};

#endif