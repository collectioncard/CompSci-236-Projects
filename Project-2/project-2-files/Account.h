//
// Created by Thomas Wessel on 5/22/20.
//

#ifndef PROJECT2FIXED_ACCOUNT_H
#define PROJECT2FIXED_ACCOUNT_H


#include <string>

class Account {

private:
    std::string name;
    long taxID;
    double balance;

protected:
    double last10Withdraws[10];
    double last10Deposits[10];

    int numDeposits = 0;
    int numWithdraws = 0;

    //These are some helper methods to ensure that the arrays are always representing the last 10 transactions
    void fixArraysEvenThoughAQueueWouldBeBetterAndThisIsMyWayOfComplaining(int newVal, int arrayToFix[]);
    void fixArraysEvenThoughAQueueWouldBeBetterAndThisIsMyWayOfComplaining(double newVal, double arrayToFix[]);
    void fixArraysEvenThoughAQueueWouldBeBetterAndThisIsMyWayOfComplaining(std::string newVal, std::string arrayToFix[]);

public:
    void setName(std::string newName);

    void setTaxID(long newTaxID);

    void setBalance(double newBalance);

    std::string getName();

    long getTaxID();

    double getBalance();

    void makeDeposit(double amount);

    void display();

    Account();

    Account(std::string newName, long newTaxID, double newBalance);

};


#endif //PROJECT2FIXED_ACCOUNT_H
