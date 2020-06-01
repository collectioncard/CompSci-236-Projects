//
// Created by Thomas Wessel on 5/22/20.
//

#include <iostream>
#include "Beer.h"
using namespace std;


Beer::Beer(){
    setBeerType("unknown beer type");
    setGlassSize(20.0);
    setLitersRemaining(0.0);
}

Beer::Beer(string beerType, double litersRemaining, double glassSize){
    setBeerType(beerType);
    setGlassSize(glassSize);
    setLitersRemaining(litersRemaining);
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
    //if(0 < tempDate && tempDate < 13){
    if(0 <= newAmount && newAmount <= glassSize){
        litersRemaining = newAmount;
    }else{
        cout << "Invalid fill amount; defaulting to full" << endl;
        litersRemaining = glassSize;
    }
}

void Beer::setGlassSize(double newGlassSize){
    //make sure that the glass size is > 0
    if(newGlassSize <= 0.0){
        cout << "Impossible glass size! defaulting to 100 liters" << endl;
        glassSize = 100;
    }else{
        glassSize = newGlassSize;
    }
}


string Beer::toString(){
    return "There is currently " + getLitersRemaining() + " of " + beerType;
}

