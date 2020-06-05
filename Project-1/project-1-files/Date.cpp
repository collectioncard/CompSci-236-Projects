//
// Created by Thomas Wessel on 5/22/20.
//

#include <iostream>
#include "Date.h"

using namespace std;

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

int Date::generateMonthInt(string month){

    if(monthNumbers.find(month) != monthNumbers.end()){
        return monthNumbers.find(month) -> second;
    }else{
        return -1;
    }
}

void Date::printDate(int format){
    cout << toString(format);
}

string Date::toString() {
    return month + " " + toString(day) + ", " + toString(year) + "\n";
}

string Date::toString(int format){
    switch(format){
        case 0:
            return month + " " + to_string(day) + ", " + to_string(year) + "\n";
            break;
        case 1:
            return to_string(day) + " " + month + " " + to_string(year) + "\n";
            break;
        case 2:
            return month + "-" + to_string(day) + "-" + to_string(year) + "\n";
            break;
        case 3:
            return to_string(generateMonthInt(month)) + "/" + to_string(day) + "/" + to_string(year) + "\n";
            break;
        default:
            return "invalid format!";
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
        cout << "Invalid day number; defaulting to 1\n";
        day = 1;
    }
}

int Date::getYear(){
    return year;
}

void Date::setYear(int newYear) {
    if(1969<newYear && newYear<3000){
        year = newYear;
    } else{
        cout << "Invalid year number; defaulting to 1969\n";
        year = 1969;
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
        month = "Jan";
        cout << "invalid month; defaulting to January\n";

    }else{
        month = newMonth;
    }
}


