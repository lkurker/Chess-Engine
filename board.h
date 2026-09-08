//board.h

#ifndef BOARD_H_EXISTS
#define BOARD_H_EXISTS

#include <iostream>
#include "piece.h"


class Board{


    private:

        std::string board[8][8];

    public: 

        Board();

        void displayBoard();




};//end class definition

#endif
