//piece.cpp

#include "piece.h"

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


void Piece:: setColor(std::string chosenColor){

    color = chosenColor;

}//end setColor

void Piece:: setPosition(std::string newPosition){

    position = newPosition;

}//end setPosition