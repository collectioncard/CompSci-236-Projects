//
// Created by Thomas Wessel on 5/22/20.
//

#include <iostream>
#include "Account.h"

using namespace std;



Account::Account(){
    name = "Unknown Name!";
    taxID = 000000000;
    balance = 00.00;
}

Account::Account(string newName, long newTaxID, double newBalance){
name = newName;
taxID = newTaxID;
balance = newBalance;
}

//These three methods are the exact same, but deal with different data types. Generics might help, but im lazy
void Account::fixArraysEvenThoughAQueueWouldBeBetterAndThisIsMyWayOfComplaining(int newVal, int arrayToFix[]) {
    for(int i = 9; i > 0; i--){
        arrayToFix[i] = arrayToFix[i-1];
    }
    arrayToFix[0] = newVal;
}
void Account::fixArraysEvenThoughAQueueWouldBeBetterAndThisIsMyWayOfComplaining(double newVal, double arrayToFix[]) {
    for(int i = 9; i > 0; i--){
        arrayToFix[i] = arrayToFix[i-1];
    }
    arrayToFix[0] = newVal;
}
void Account::fixArraysEvenThoughAQueueWouldBeBetterAndThisIsMyWayOfComplaining(std::string newVal, std::string arrayToFix[]) {
    for(int i = 9; i > 0; i--){
        arrayToFix[i] = arrayToFix[i-1];
    }
    arrayToFix[0] = newVal;
}


void Account::setName(string newName){
    name = newName;
}

void Account::setTaxID(long newTaxID){
    taxID = newTaxID;
}

void Account::setBalance(double newBalance){
    balance = newBalance;
}

string Account::getName(){
    return name;
}

long Account::getTaxID(){
    return taxID;
}

double Account::getBalance(){
    return balance;
}

void Account::makeDeposit(double amount){
    balance+=amount;
    fixArraysEvenThoughAQueueWouldBeBetterAndThisIsMyWayOfComplaining(amount, last10Deposits);
}

void  Account::display(){

    std::cout << "Account holder name: " << getName() <<
                "\nTax ID # " << getTaxID() <<
                "\nCurrent Balance: " << getBalance() << std::endl;
}



