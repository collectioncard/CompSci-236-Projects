//
// Created by Thomas Wessel on 5/22/20.
//

#include <iostream>
#include "Date.h"

using namespace std;

int Date::generateMonthInt(string month){
    int tempDate = -1;

    //maps are weird in c++, map.find returns an iterator type - we want the second item in the list, so we call -> second
    tempDate = monthNumbers.find(month)->second;
    if(0 < tempDate && tempDate < 13){
        return tempDate;
    }else{
        return -1;
    }



}



//begin constructors
Date::Date(){
    setYear(1970);
    setMonth("Jan");
    setDay(1);
}

Date::Date(int year, string month, int day){
    setYear(year);
    setMonth(month);
    setDay(day);
}

//end constructors

//prints requested date format - none of them are 8601 :(
/*Also, this function seems weird to me. Why are we printing something from an adt and does this replace the tostring
 * method? I this seems to be... off.
 */
void Date::printDate(int format){
    switch(format){
        case 0:
            cout << month << " " << day << ", " << year << endl;
            break;
        case 1:
            cout << day << " " << month << " " << year << endl;;
            break;
        case 2:
            cout << generateMonthInt(month) << "-" << day << "-" << year << endl;;
            break;
        case 3:
            cout << generateMonthInt(month) << "/" << day << "/" << year << endl;;
            break;
        default:
            cout << "invalid format!";
            break;
    }
}


//getters and setters
int Date::getDay(){
    return day;
}

void Date::setDay(int newDay) {
    if(0<newDay && newDay<32){
        day = newDay;
    } else{
        cout << "Invalid day number";
    }
}

int Date::getYear(){
    return year;
}

void Date::setYear(int newYear) {
    if(1969<newYear && newYear<3000){
        year = newYear;
    } else{
        cout << "Invalid year number";
    }
}

const string Date::getMonth() {
    return month;
}

void Date::setMonth( string newMonth) {
    //It is possible that the user could enter a month in different cases. The spec shows them in lowercase so ill change the string

    //nevermind... that looks complicated and I dont think we have learned that yet. (This is why C++ isnt my main language)


    //I'm just gonna call generate month int and see if it can find the correct value
    int isValid = generateMonthInt(newMonth);
    if(isValid == -1){
        month = "error";
        cout << "invalid month\n";
    }else{
        month = newMonth;

    }
}

