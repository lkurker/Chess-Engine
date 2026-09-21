//board.cpp
#include "board.h"


Board::Board(){

    //We will set the constant files in order to determine whether a piece can shift right or left
    for(int i = 0; i < 8; i++){

        A_FILE = A_FILE | 1ULL << (i * 8);
        H_FILE = H_FILE | 1ULL << ((i * 8) + 7);

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

//Testing bitboard shifts. This function may not be used in the final implementation
uint64_t Board::shiftUp(uint64_t board){

    board = board << 8;
    return board;

}//end shiftUp

uint64_t Board::shiftDown(uint64_t board){

    board = board >> 8;
    return board;

}//end shiftDown

//Shifting pieces left and right. NOTE: This will be shifting left and right from the board's perspective,
//and since this is inverted to how shifting left and right is for bitwise operations, the operations are
//purposefully flipped for these methods specifically.
uint64_t Board::shiftLeft(uint64_t board){

    board = (board & ~(getA_File())) >> 1;
    return board;

}//end shiftLeft

uint64_t Board::shiftRight(uint64_t board){

    board = (board & ~(getH_File())) << 1;
    return board;

}//end shiftRight



//getters for the A and H files
uint64_t Board::getA_File(){

    return A_FILE;

}//end getA_File

uint64_t Board:: getH_File(){

    return H_FILE;

}//end getH_File



