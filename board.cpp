//board.cpp
#include "board.h"


Board::Board(){

    for(int i = 0; i < 8; i++){

        for(int j = 0; j < 8; j++){

            board[i][j] = ".";

        }//end for loop

    }//end for loop

}//end constructor

void Board::displayBoard(){

    for(int i = 0; i < 8; i++){

        for(int j = 0; j < 8; j++){

            std::cout << board[i][j];
            std::cout << " ";

        }//end for loop

        std::cout << "" << std::endl;

    }//end for loop

}//end displayBoard