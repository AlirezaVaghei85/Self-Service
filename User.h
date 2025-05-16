#ifndef USER_H_INCLUDE
#define USER_H_INCLUDE
#include <iostream>
using namespace std;

class User
{
private:
    int userID;
    string name;
    string lastName;
    string hashedPassword;

public:
    virtual void print() const;
    virtual void getType();

    int getUserID() { return userID; }
    string getName() { return name; }
    string getLastName() { return lastName; }
    string getHashedPassword() { return hashedPassword; }

    void setUserID(int i) { userID = i; }
    void setName(string n) { name = n; }
    void setLastName(string n) { lastName = n; }
    void setHashedPassword(string h) { hashedPassword = h; }
};

#endif