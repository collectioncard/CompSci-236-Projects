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
    Beer beer("budweiser",  20.0,  30.0);
    cout << beer.toString() << "\n";

    cout << "Press enter to continue";
    cin >> temp;

}

void dateSubMenu(){
    //create temp var so we can pause. Not sure if there is a better way to do this...
    string temp;
    //testing no-arg
    cout << "Testing no-arg constructor\n";
    Date dateNoArg;
    dateNoArg.printDate(0);
    dateNoArg.printDate(1);
    dateNoArg.printDate(2);
    dateNoArg.printDate(3);

    cout << "\n\nTesting 'normal' constructor\n";

    Date date(2000, "Feb", 29);
    date.printDate(0);
    date.printDate(1);
    date.printDate(2);
    date.printDate(3);

    cout << "Press enter to continue";
    cin >> temp;

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
