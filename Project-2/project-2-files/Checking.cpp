//
// Created by Thomas Wessel on 5/22/20.
//

#include "Checking.h"
#include "iostream"

Checking::Checking() {
    setName("Unknown Name");
    setTaxID(000000000);
    setBalance(0);
}

Checking::Checking(std::string name, long taxID, double balance) {
    setName(name);
    setTaxID(taxID);
    setBalance(balance);
}

void Checking::writeCheck(int checkNum, double amnt) {
    if(amnt > getBalance()){
        std::cout << "Insufficient funds!";
        return;
    }else if(amnt < 0){
        std::cout << "Cannot write a check for a negative amount!\nThis will not be saved!" << std::endl;
    }
    setBalance(getBalance() - amnt);
    numWithdraws++;
    //WHY are we using an array for this? It would be less annoying to implement if we did this using a queue for this instead
    //We would also be able to log more than 10 transactions
    fixArrays(checkNum, last10Checks);
    fixArrays(amnt, last10Withdraws);
}

void Checking::display() {
    std::cout << "\nTotal Number of Checks: " << numWithdraws <<
                "\nLast 10 Checks: " << std::endl;

    for(int i = 0; i < 10; i++){
        if(i == numWithdraws){
            break;
        }
        std::cout << "Check #" << last10Checks[i] << " for the amount $" << last10Withdraws[i] << std::endl;
    }

    std::cout << "\nTotal Number of Deposits: " << numDeposits <<
                 "\nLast 10 Deposit amounts:" << std::endl;

    for(int i = 0; i < 10; i++){
        if(i == numDeposits ){
            break;
        }
        std::cout << "Deposit " << i + 1  << " in the amount of $" << last10Deposits[i] << std::endl;
    }
}