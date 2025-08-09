#ifndef ADMIN_H_INCLUDE
#define ADMIN_H_INCLUDE
#include <iostream>
#include "User.h"
using namespace std;

class Admin : public User
{
private:
public:
    Admin()
    {
        setName(" ");
        setLastName(" ");
    }
    void print() const {}
    void getType() {}
};

#endif