/******************************************Project 2 CompSci 236********************************************
 *                                                                                                         *
 *                                      ~~~~2020 Thomas Wessel~~~~                                         *
 *                                                                                                         *
 * This project does very little error checking but it works well enough for what the project required.    *
 * The Checking, CreditCard and Savings classes are children of the Account class. This project was mostly *
 * a test to make sure that the class was able to understand inheritance 'n stuff.                         *
 **********************************************************************************************************/


#include <iostream>
#include "Checking.h"
#include "CreditCard.h"
#include "Savings.h"


using namespace std;

int main(int argc, const char * argv[]) {
    string userName;
    long taxID;
    //This is a temp var that we use to store the amount the user wants to change in an account
    double amnt;
    string chargeName;


    //Gather the User's info
    cout<< "Please Enter your name:";
    cin >> userName;
    cout << "\nPlease Enter your Tax ID number:";
    cin >> taxID;
    cout << "\n\n";

    // Create objects with $100 starting balance
    Checking checking(userName, taxID, 100.00);
    Savings savings(userName, taxID, 100.00);
    CreditCard creditCard(userName, taxID, 100.00);


    //Start menu loop
    bool loop = true;
    int selection = -1;

    do{
        cout << "Checking Balance: $" << checking.getBalance() << "     Savings Balance: $" << savings.getBalance() << "    Credit Card Balance: $ " << creditCard.getBalance() << endl;
        cout << "1. Savings Deposit\n" <<
             "2. Savings Withdrawal\n" <<
             "3. Checking Deposit\n" <<
             "4. Write A Check\n" <<
             "5. Credit Card Payment\n" <<
             "6. Make A Charge\n" <<
             "7. Display Savings\n"
             "8. Display Checking\n" <<
             "9. Display Credit Card\n" <<
             "0. Exit\n" <<
             "Selection: ";

        cin >> selection;

        switch (selection) {
            case 1:
                cout << "Please enter a value to deposit\n>";
                cin >> amnt;
                savings.makeDeposit(amnt);
                break;
            case 2:
                cout << "Please enter a value to withdraw\n>";
                cin >> amnt;
                savings.doWithdraw(amnt);
                break;
            case 3:
                cout << "Please enter a value to deposit\n>";
                cin >> amnt;
                checking.makeDeposit(amnt);
                break;
            case 4:
                cout << "Please enter the check amount\n>";
                cin >> amnt;
                cout << "Please enter the check number\n>";
                int checkNum;
                cin >> checkNum;
                checking.writeCheck(checkNum,amnt);
                break;
            case 5:
                cout << "How much would you like to pay\n>";
                cin >> amnt;
                creditCard.makePayment(amnt);
                break;
            case 6:
                cout << "How much would you like to charge\n>";
                cin >> amnt;
                cout << "What is the name of the transaction\n>";
                cin >> chargeName;
                creditCard.DoCharge(chargeName,amnt);
                break;
            case 7:
                savings.display();
                break;
            case 8:
                checking.display();
                break;
            case 9:
                creditCard.display();
                break;
            case 0:
                loop = false;
                //Or, since I dont have to do anything after this, I could just return here and not have to worry about logic...
                break;
            default:
                cout << "Sorry, that isn't a valid option, please try again";
                break;


        }

        //Separate the last menu from the new
        cout << "\n\n\n";

    }while(loop);


    return 0;
}