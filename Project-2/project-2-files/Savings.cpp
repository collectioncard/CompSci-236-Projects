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
        std::cout << "Insufficient funds!" << std::endl;
        return;
    }else if(amnt < 0){
        std::cout << "Cannot withdraw a negative amount!" << std::endl;
        return;
    }
    setBalance(getBalance() - amnt);
    numWithdraws++;
    //WHY are we using an array for this? It would be less annoying to implement if we did this using a queue for this instead
    //We would also be able to log more than 10 transactions

    fixArrays(amnt, last10Withdraws);
}

void Savings::display() {
    std::cout << "\nTotal Number of Withdrawals: " << numWithdraws <<
              "\nLast 10 Withdrawals: " << std::endl;

    for(int i = 0; i < 10; i++){
        if(i == numWithdraws){
            break;
        }
        std::cout << "Withdrawal " << i + 1  << " for the amount $" << last10Withdraws[i] << std::endl;
    }

    std::cout << "\nTotal Number of Deposits: " << numDeposits <<
              "\nLast 10 Deposit amounts:" << std::endl;

    for(int i = 0; i < 10; i++){
        if(i == numDeposits ){
            break;
        }
        std::cout << "Deposit " << i + 1  << " in the amount $" << last10Deposits[i] << std::endl;
    }
}


