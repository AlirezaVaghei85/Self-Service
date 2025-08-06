#ifndef TRANSACTION_H_INCLUDE
#define TRANSACTION_H_INCLUDE
#include <iostream>
using namespace std;

enum TransactionType
{
    TRANSFER,
    PAYMENT
};

enum TransactionStatus
{
    PENDING,
    COMPLETED,
    FAILED
};

class Transaction
{
private:
    static int nextID;
    string trackingCode;
    float amount;
    TransactionType type;
    TransactionStatus status;
    time_t created_AT;

public:
    int ID;
    Transaction();

    void setTransactionID(int i) { ID = i; }
    void setTrackingCode(int i) { trackingCode = i; }
    void setAmount(int i) { amount = i; }
    void setType(TransactionType t) { type = t; }
    void setStatus(TransactionStatus s) { status = s; }
    void setTime(time_t T) { created_AT = T; }

    int getTransactionID() { return ID; }
    string getTrackingCode() { return trackingCode; }
    float getAmount() { return amount; }
};

// int MyClass::nextID = 0;

#endif