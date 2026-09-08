//piece.h

#ifndef PIECE_H_EXISTS
#define PIECE_H_EXISTS

#include <iostream>

class Piece{


    private:

        Piece();
        std::string color;
        int value();
        std::string position;
        std::string name;

    public:

        bool legalMove(std::string newPosition);
        std::string getColor();
        std::string getPosition();
        std::string getName();

        void setColor(std::string chosenColor);
        void setPosition(std::string newPosition);


};//end class definition

#endif