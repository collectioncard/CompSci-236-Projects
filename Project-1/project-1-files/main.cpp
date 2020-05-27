#include <iostream>
#include "Beer.h"
#include "Date.h"

using namespace std;

void beerSubMenu(){
    //create temp var so we can pause. Not sure if there is a better way to do this...
    string temp;
    cout << "\nTesting no-arg constructor" << endl;
    Beer beerNoArg;
    cout << beerNoArg.toString()<<endl;

    cout << "\nTesting other constructor" << endl;
    cout << "What type of beer would you like to drink?\n>";
    string beerName;
    cin.ignore();
    getline(cin, beerName);

    cout << "What glass size would you like for your beer? (in Liters)\n>";
    double glassSize;
    cin >> glassSize;
    cout << "How full would you like the glass? Chose a value between 0 and " << glassSize << "\n>";
    double fillAmnt;
    cin >>fillAmnt;
    Beer beer(beerName, fillAmnt, glassSize);
    cout << beer.toString() << "\n\n\n";
}

void dateSubMenu(){
    //create temp var so we can pause. Not sure if there is a better way to do this...
    string temp;
    //testing no-arg
    cout << "\n\nTesting no-arg constructor\n";
    Date dateNoArg;
    dateNoArg.printDate(0);
    dateNoArg.printDate(1);
    dateNoArg.printDate(2);
    dateNoArg.printDate(3);

    cout << "\n\nTesting 'normal' constructor\n";

    cout << "Please enter a year.\n>";
    int year;
    cin >> year;
    cout << "Please enter a month.\n>";
    string month;
    cin >> month;
    cout << "Please enter a day.\n>";
    int day;
    cin >> day;

    Date date(year, month, day);
    date.printDate(0);
    date.printDate(1);
    date.printDate(2);
    date.printDate(3);
    cout << "\n\n";
}

int main() {


    //Create menu loop
    bool loop = true;
    int choice = -1;
    do{

        cout << "Welcome to Project One!\n";
        cout << "-----------------------------------------\n";
        cout << "Class List:\n";
        cout << "1. Beer\n";
        cout << "2. Date\n";
        cout << "3. Exit\n";
        cout << "Please choose a program: ";
        cin >> choice;

        switch (choice) {
            case 1:
                beerSubMenu();
                break;
            case 2:
                dateSubMenu();
                break;
            case 3:
                loop = false;
                break;
            default:
                cout << "Sorry, that is not an option. Please try again.";
                break;
        }
    }while (loop);



    return 0;
}
