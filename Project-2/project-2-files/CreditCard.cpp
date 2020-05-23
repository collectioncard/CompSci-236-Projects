//
// Created by Thomas Wessel on 5/22/20.
//

#include <iostream>
#include "CreditCard.h"

CreditCard::CreditCard() {
    setName("Unknown Name");
    setTaxID(000000000);
    setBalance(0);
}

CreditCard::CreditCard(std::string name, long taxID, double balance) {
    setName(name);
    setTaxID(taxID);
    setBalance(balance);
}

void CreditCard::DoCharge(std::string name, double amnt) {

    setBalance(getBalance() + amnt);
    numWithdraws++;
    //WHY are we using an array for this? It would be less annoying to implement if we did this using a queue for this instead
    //We would also be able to log more than 10 transactions
    fixArraysEvenThoughAQueueWouldBeBetterAndThisIsMyWayOfComplaining(name, last10Charges);
    fixArraysEvenThoughAQueueWouldBeBetterAndThisIsMyWayOfComplaining(amnt, last10Withdraws);
}

void CreditCard::makePayment(double amnt) {
    if(amnt > Account::getBalance() ){
        Account::setBalance(0);
    }else{
        Account::setBalance(Account::getBalance() - amnt);
    }

}

void CreditCard::display() {
    std::cout << "Number of transactions: " << numWithdraws <<
              "\nLast 10 charges: " << std::endl;

    for(int i = 0; i < 9; i++){
        std::cout << "Charge Name: " << last10Charges[i] << " for the amount $" << last10Withdraws[i] << std::endl;
    }

    std::cout << "Last 10 Deposit amounts:" << std::endl;

    for(int i = 0; i < 9; i++){
        std::cout << "$" << last10Deposits[i] << std::endl;
    }
}

