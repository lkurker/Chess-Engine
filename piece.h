//piece.h

#ifndef PIECE_H_EXISTS
#define PIECE_H_EXISTS

#include <iostream>

class Piece{


    private:

        
        std::string color;
        int value();
        std::string position;
        std::string name;

    public:

        Piece();
        Piece(std::string name, std::string color);

        bool legalMove(std::string newPosition);
        std::string getColor();
        std::string getPosition();
        std::string getName();

        void setColor(std::string chosenColor);
        void setPosition(std::string newPosition);
        void setName(std::string name);

};//end class definition

#endif