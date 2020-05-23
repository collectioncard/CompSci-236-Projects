//
// Created by Thomas Wessel on 5/22/20.
//

#ifndef PROJECTONEFIXED_BEER_H
#define PROJECTONEFIXED_BEER_H


#include <string>

class Beer {
private:
    std::string beerType;
    double litersRemaining;
    bool isEmpty;
    double glassSize = 20.0;

public:
    Beer();

    Beer(std::string beerType, double litersRemaining, double glassSize);

    std::string getBeerType();

    std::string getLitersRemaining();

    int getGlassSize();

    void setBeerType(std::string newType);

    void setLitersRemaining(double newAmount);

    void setGlassSize(double newGlassSize);

    std::string toString();

};


#endif //PROJECTONEFIXED_BEER_H
