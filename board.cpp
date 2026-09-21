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


int Board::getPosition(std::string position){

    int rank = (position[1] - 1) * 8;
    int file = position[0] - 'a';

    int chessPosition = rank + file;
    return chessPosition;

}//end getPosition

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
uint64_t Board::setSquare(uint64_t board, std::string position){

    int chessPosition = getPosition(position);
    
    board = board | (1ULL << chessPosition);

    return board;


}//end setSquare

uint64_t Board::clearSquare(uint64_t board, std::string position){

    int chessPosition = getPosition(position);

    uint64_t mask = 1ULL << chessPosition;
    board &= ~mask;

    return board;


}//end clearSquare


uint64_t Board::toggleSquare(uint64_t board, std::string position){

    int chessPosition = getPosition(position);
    uint64_t mask = 1ULL << chessPosition;
    board = board ^ mask;
    return board;


}//end toggleSquare


 //Checking to see if the board is set at a specific position
bool Board::isSquareSet(uint64_t board, std::string position){

    int chessPosition = getPosition(position);
    
    return board & (1ULL << chessPosition);

}//end isSquareSet

//Getters for returning occupied and empty spaces depending on the bitboards that are passed as parameters
uint64_t Board::getOccupied(uint64_t whitePieces, uint64_t blackPieces){

    uint64_t occupied = whitePieces | blackPieces;
    return occupied;

}//end getOccupied

uint64_t Board::getEmpty(uint64_t whitePieces, uint64_t blackPieces){

    uint64_t empty = ~(whitePieces | blackPieces);
    return empty;

}//end getEmpty



