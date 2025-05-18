#ifndef SESSIONBASE_INCLUDE
#define SESSIONBASE_H_INCLUDE
#include <iostream>
using namespace std;

enum SessionStatus
{
    AUTHENTICATED,
    ANONYMOUS
};

class SessionBase
{
protected:
    time_t createdAt;
    time_t lasttimeLogin;
    SessionStatus status;
    virtual void load_session() = 0;
    virtual void save_session() = 0;

public:
    virtual void login(string, string) = 0;
    virtual void logout() = 0;
};

#endif