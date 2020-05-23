//
// Created by Thomas Wessel on 5/22/20.
//

#ifndef PROJECT2FIXED_SAVINGS_H
#define PROJECT2FIXED_SAVINGS_H


#include "Account.h"

class Savings : public Account{

public:
    Savings();

    Savings(std::string name, long taxID, double balance);

    void doWithdraw(double amnt);

    void display();
};


#endif //PROJECT2FIXED_SAVINGS_H
