//
// Created by Thomas Wessel on 5/22/20.
//

#include <iostream>
#include "Savings.h"

Savings::Savings() {
    setName("Unknown Name");
    setTaxID(000000000);
    setBalance(0);
}

Savings::Savings(std::string name, long taxID, double balance) {
    setName(name);
    setTaxID(taxID);
    setBalance(balance);
}

void Savings::doWithdraw(double amnt) {
    if(amnt > getBalance()){
        std::cout << "Insufficient funds!";
        return;
    }
    setBalance(getBalance() - amnt);
    numWithdraws++;
    //WHY are we using an array for this? It would be less annoying to implement if we did this using a queue for this instead
    //We would also be able to log more than 10 transactions

    fixArraysEvenThoughAQueueWouldBeBetterAndThisIsMyWayOfComplaining(amnt, last10Withdraws);
}

void Savings::display() {
    std::cout << "Number of transactions: " << numWithdraws <<
              "\nLast 10 Withdrawals: " << std::endl;

    for(int i = 0; i < 9; i++){
        std::cout << "Withdrawal" << i + 1  << " for the amount $" << last10Withdraws[i] << std::endl;
    }

    std::cout << "Last 10 Deposit amounts:" << std::endl;

    for(int i = 0; i < 9; i++){
        std::cout << "$" << last10Deposits[i] << std::endl;
    }
}


