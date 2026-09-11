//piece.cpp

#include "piece.h"


//constructor
Piece::Piece(){

    name = ".";
    color = "none";

}//end constructor

Piece::Piece(std::string newName, std::string newColor){

    name = newName;
    color = newColor;

}

//class definitions that are universal for each piece
std::string Piece::getColor(){

    return color;

}//end getColor

std::string Piece::getPosition(){

    return position;

}//end getPosition

std::string Piece::getName(){

    return name;

}//end getName


void Piece::setColor(std::string chosenColor){

    color = chosenColor;

}//end setColor

void Piece::setPosition(std::string newPosition){

    position = newPosition;

}//end setPosition

void Piece::setName(std::string newName){

    name = newName;

}