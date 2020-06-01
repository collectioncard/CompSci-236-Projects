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
    if(amnt < 0){
        std::cout << "Cannot charge a negative amount" << std::endl;
    }else{
        setBalance(getBalance() + amnt);
        numWithdraws++;
        //WHY are we using an array for this? It would be less annoying to implement if we did this using a queue for this instead
        //We would also be able to log more than 10 transactions
        fixArrays(name, last10Charges);
        fixArrays(amnt, last10Withdraws);
    }

}

void CreditCard::makePayment(double amnt) {
    if(amnt > Account::getBalance() ){
        std::cout << "Cannot pay more than balance; setting balance to zero" << std::endl;
        Account::setBalance(0);
        numDeposits++;
    }else if(amnt < 0){
        std::cout << "Cannot pay a negative amount!" << std::endl;
    }else{
        Account::setBalance(Account::getBalance() - amnt);
        fixArrays(amnt, last10Deposits);
        numDeposits++;
    }

}

void CreditCard::display() {
    std::cout << "\n\nTotal number of charges: " << numWithdraws <<
              "\nLast 10 charges: " << std::endl;

    for(int i = 0; i < 10; i++){
        if(i == numWithdraws ){
            break;
        }
        std::cout << "Charge Name: " << last10Charges[i] << " for the amount $" << last10Withdraws[i] << std::endl;
    }

    std::cout << "\nTotal Number of Payments: " << numDeposits <<"\nLast 10 Payments:" << std::endl;

    for(int i = 0; i < 10; i++){
        if(i == numDeposits ){
            break;
        }
        std::cout << "Payment " << i + 1  << " in the amount of $" << last10Deposits[i] << std::endl;
    }
}

