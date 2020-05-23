//
// Created by Thomas Wessel on 5/22/20.
//

#include "Beer.h"
using namespace std;


Beer::Beer(){
    setBeerType("unknown beer type");
    setLitersRemaining(0.0);
    setGlassSize(20.0);

}

Beer::Beer(string beerType, double litersRemaining, double glassSize){
    setBeerType(beerType);
    setLitersRemaining(litersRemaining);
    setGlassSize(glassSize);
}


string Beer::getBeerType(){
    return beerType;
}

string Beer::getLitersRemaining(){
    return to_string(litersRemaining) + "/" + to_string(glassSize) + " liters";
}

int Beer::getGlassSize(){
    return glassSize;
}

void Beer::setBeerType(string newType){
    beerType = newType;
}
void Beer::setLitersRemaining(double newAmount){
    litersRemaining = newAmount;
}

void Beer::setGlassSize(double newGlassSize){
    glassSize = newGlassSize;
}


string Beer::toString(){
    return "There is currently " + getLitersRemaining() + " of " + beerType;
}

