//
// Created by Thomas Wessel on 5/22/20.
//

#ifndef PROJECT2FIXED_CHECKING_H
#define PROJECT2FIXED_CHECKING_H


#include "Account.h"

class Checking : public Account {

private:
    int last10Checks[10];

public:

    Checking();
    Checking(std::string name, long taxID, double balance);

    void writeCheck(int checkNum, double amnt);

    void display();

};


#endif //PROJECT2FIXED_CHECKING_H
