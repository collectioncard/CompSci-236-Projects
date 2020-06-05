//
// Created by Thomas Wessel on 5/22/20.
//

#ifndef PROJECTONEFIXED_DATE_H
#define PROJECTONEFIXED_DATE_H


#include <string>
#include <map>

class Date {

private:
    int day;
    int year;
    std::string month;

    //used for month validation and easy conversion between month name and number
    const std::map<std::string, int> monthNumbers{
            {"Jan", 1},
            {"Feb", 2},
            {"Mar", 3},
            {"Apr", 4},
            {"May", 5},
            {"Jun", 6},
            {"Jul", 7},
            {"Aug", 8},
            {"Sep", 9},
            {"Oct", 10},
            {"Nov", 11},
            {"Dec", 12}
    };

    int generateMonthInt(std::string month);

public:
    //begin constructors
    Date();

    Date(int year, std::string month, int day);

    //end constructors

    //prints requested date format - none of them are 8601 :(
    /*Also, this function seems weird to me. Why are we printing something from an adt and does this replace the tostring
     * method? I this seems to be... off.
     */
    void printDate(int format);

    //override that returns a default string
    std::string toString();
    std::string toString(int format);

    //getters and setters
    int getDay();

    void setDay(int newDay);

    int getYear();

    void setYear(int newYear);

    const std::string getMonth();

    void setMonth( std::string newMonth);
};


#endif //PROJECTONEFIXED_DATE_H
