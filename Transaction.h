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
    int transactionID;
    string trackingCode;
    float amont;
    TransactionType type;
    TransactionStatus status;
    time_t created_AT;

public:
};

#endif