//
// Created by Thomas Wessel on 5/22/20.
//

#ifndef PROJECT2FIXED_CREDITCARD_H
#define PROJECT2FIXED_CREDITCARD_H


#include "Account.h"

class CreditCard : public Account{

private:
    long cardNumber;
    std::string last10Charges[10];

public:
    CreditCard();

    CreditCard(std::string name, long taxID, double balance);

    void DoCharge(std::string name, double amount);

    void makePayment(double amnt);

    void display();

};


#endif //PROJECT2FIXED_CREDITCARD_H
