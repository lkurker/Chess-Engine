//board.cpp
#include "board.h"


Board::Board(){

    //Array of piece names to make setting the board up easier
    std::string whitePieces[8] = {"R", "N", "B", "Q", "K", "B", "N", "R"};
    std::string blackPieces[8] = {"r", "n", "b", "q", "k", "b", "n", "r"};



    for(int i = 0; i < 8; i++){

        for(int j = 0; j < 8; j++){

            //certain conditions will be set for pieces in the top or bottom two rows
            if(i == 0){

                board[i][j] = blackPieces[j];

            }//end if statement

            else if(i == 1){

                board[i][j] = "p";

            }//end else if statement

            else if(i == 6){

                board[i][j] = "P";

            }//end else if statement

            else if(i == 7){

                board[i][j] = whitePieces[j];

            }//end else if statement


            else{

                board[i][j] = ".";

            }//end else statement
            

        }//end for loop

    }//end for loop

}//end constructor

void Board::displayBoard(uint64_t board){

    std::cout << "   abcdefgh" << std::endl;

    for(int i = 7; i > -1; i--){

        std::cout << (i + 1) << "  ";

        for(int j = 0; j < 8; j++){

            if(board & (1ULL << (i*8 + j))){

                std::cout << "1";

            }//end if statement

            else{

                std::cout << "0";

            }//end else statement

        }//end for loop

        std::cout << "" << std::endl;

    }//end for loop

}//end displayBoard

//This function is only used to turn one piece of the bitboard on at a given position
uint64_t Board::setSquare(uint64_t chessBoard, std::string position){

    int rank = (position[1] - 1) * 8;
    int file = position[0] - 'a';

    int chessPosition = rank + file;
    chessBoard = chessBoard | (1ULL << chessPosition);

    return chessBoard;


}//end setSquare

