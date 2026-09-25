//board.cpp
#include "board.h"


Board::Board(){

    //We will set the constant files in order to determine whether a piece can shift right or left
    for(int i = 0; i < 8; i++){

        A_FILE = A_FILE | 1ULL << (i * 8);
        H_FILE = H_FILE | 1ULL << ((i * 8) + 7);

    }//end for loop

    //Setting up the chess board to its normal configuration
    for(int i = 0; i < 8; i++){

        whitePawns = whitePawns | 1ULL << (8 + i);
        blackPawns = blackPawns | 1ULL << (48 + i);

    }

    //Now to set the rest of the pieces at their specific spots
    whiteRooks = whiteRooks | 1ULL << 0;
    whiteRooks = whiteRooks | 1ULL << 7;
    blackRooks = blackRooks | 1ULL << 56;
    blackRooks = blackRooks | 1ULL << 63;

    whiteKnights = whiteKnights | 1ULL << 1;
    whiteKnights = whiteKnights | 1ULL << 6;
    blackKnights = blackKnights | 1ULL << 57;
    blackKnights = blackKnights | 1ULL << 62;

    whiteBishops = whiteBishops | 1ULL << 2;
    whiteBishops = whiteBishops | 1ULL << 5;
    blackBishops = blackBishops | 1ULL << 58;
    blackBishops = blackBishops | 1ULL << 61;

    whiteQueens = whiteQueens | 1ULL << 3;
    whiteKing = whiteKing | 1ULL << 4;
    blackQueens = blackQueens | 1ULL << 59;
    blackKing = blackKing | 1ULL << 60;

    whitePieces = whitePawns | whiteKnights | whiteBishops | whiteRooks | whiteQueens | whiteKing;
    blackPieces = blackPawns | blackKnights | blackBishops | blackRooks | blackQueens | blackKing;

    occupied = whitePieces | blackPieces;
    empty = ~occupied;

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
//These two methods will eventually be deleted. They are here for testing purposes 
uint64_t Board::getOccupied(uint64_t whitePieces, uint64_t blackPieces){

    uint64_t testOccupied = whitePieces | blackPieces;
    return testOccupied;

}//end getOccupied

uint64_t Board::getEmpty(uint64_t whitePieces, uint64_t blackPieces){

    uint64_t testEmpty = ~(whitePieces | blackPieces);
    return testEmpty;

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



//getters for the different private bitboards
uint64_t Board::getA_File(){

    return A_FILE;

}//end getA_File

uint64_t Board:: getH_File(){

    return H_FILE;

}//end getH_File

uint64_t Board::getKingMovement(){

    return kingMovement;

}//end getKingMovement

uint64_t Board::getKnightMovement(){

    return knightMovement;

}//end getKnightMovement

uint64_t Board::getBishopMovement(){

    return bishopMovement;

}//end getBishopMovement

uint64_t Board::getRookMovement(){

    return rookMovement;

}//end getRookMovement

uint64_t Board::getQueenMovement(){

    return queenMovement;

}//end getQueenMovement

uint64_t Board::getWhitePawns(){

    return whitePawns;

}

uint64_t Board::getWhiteKnights(){

    return whiteKnights;

}

uint64_t Board::getWhiteBishops(){

    return whiteBishops;

}

uint64_t Board::getWhiteRooks(){

    return whiteRooks;

}

uint64_t Board::getWhiteQueens(){

    return whiteQueens;

}

uint64_t Board::getWhiteKing(){

    return whiteKing;

}

uint64_t Board::getBlackPawns(){

    return blackPawns;

}

uint64_t Board::getBlackKnights(){

    return blackKnights;

}

uint64_t Board::getBlackBishops(){

    return blackBishops;

}

uint64_t Board::getBlackRooks(){

    return blackRooks;

}

uint64_t Board::getBlackQueens(){

    return blackQueens;

}

uint64_t Board::getBlackKing(){

    return blackKing;

}

uint64_t Board::getWhitePieces(){

    return whitePieces;

}

uint64_t Board::getBlackPieces(){

    return blackPieces;

}

uint64_t Board::getOccupied(){

    return occupied;

}

uint64_t Board::getEmpty(){

    return empty;

}


//This method will set the possible movements for the king given a position
void Board::potentialKingMoves(uint64_t kings){

    //First we must make a copy of the king board so that the original configuration isn't altered
    uint64_t kingCopy = kings;
    kingMovement = 0;

    //We will shift it in 8 different ways, apply these changes to kingMovement, and then revert the copy back to the original
    kingCopy = shiftLeft(kingCopy);
    kingMovement = kingMovement | kingCopy;
    kingCopy = kings;
    kingCopy = shiftRight(kingCopy);
    kingMovement = kingMovement | kingCopy;
    kingCopy = kings;
    kingCopy = shiftUp(kingCopy);
    kingMovement = kingMovement | kingCopy;
    kingCopy = kings;
    kingCopy = shiftDown(kingCopy);
    kingMovement = kingMovement | kingCopy;
    kingCopy = kings;

    //Now for the diagonals
    kingCopy = shiftLeft(kingCopy);
    kingCopy = shiftUp(kingCopy);
    kingMovement = kingMovement | kingCopy;
    kingCopy = kings;
    kingCopy = shiftLeft(kingCopy);
    kingCopy = shiftDown(kingCopy);
    kingMovement = kingMovement | kingCopy;
    kingCopy = kings;
    kingCopy = shiftRight(kingCopy);
    kingCopy = shiftUp(kingCopy);
    kingMovement = kingMovement | kingCopy;
    kingCopy = kings;
    kingCopy = shiftRight(kingCopy);
    kingCopy = shiftDown(kingCopy);
    kingMovement = kingMovement | kingCopy;
    kingCopy = kings;

}//end potentialKingMoves

//Now we will do the same for knight movements
void Board::potentialKnightMoves(uint64_t knights){

    uint64_t knightCopy = knights;
    knightMovement = 0;

    //Knights move in an L shape, which can be configured in 8 different ways
    knightCopy = shiftUp(knightCopy);
    knightCopy = shiftUp(knightCopy);
    knightCopy = shiftRight(knightCopy);
    knightMovement = knightMovement | knightCopy;

    knightCopy = knights;
    knightCopy = shiftUp(knightCopy);
    knightCopy = shiftUp(knightCopy);
    knightCopy = shiftLeft(knightCopy);
    knightMovement = knightMovement | knightCopy;

    knightCopy = knights;
    knightCopy = shiftDown(knightCopy);
    knightCopy = shiftDown(knightCopy);
    knightCopy = shiftLeft(knightCopy);
    knightMovement = knightMovement | knightCopy;

    knightCopy = knights;
    knightCopy = shiftDown(knightCopy);
    knightCopy = shiftDown(knightCopy);
    knightCopy = shiftRight(knightCopy);
    knightMovement = knightMovement | knightCopy;

    knightCopy = knights;
    knightCopy = shiftRight(knightCopy);
    knightCopy = shiftRight(knightCopy);
    knightCopy = shiftUp(knightCopy);
    knightMovement = knightMovement | knightCopy;

    knightCopy = knights;
    knightCopy = shiftRight(knightCopy);
    knightCopy = shiftRight(knightCopy);
    knightCopy = shiftDown(knightCopy);
    knightMovement = knightMovement | knightCopy;

    knightCopy = knights;
    knightCopy = shiftLeft(knightCopy);
    knightCopy = shiftLeft(knightCopy);
    knightCopy = shiftUp(knightCopy);
    knightMovement = knightMovement | knightCopy;

    knightCopy = knights;
    knightCopy = shiftLeft(knightCopy);
    knightCopy = shiftLeft(knightCopy);
    knightCopy = shiftDown(knightCopy);
    knightMovement = knightMovement | knightCopy;


}//end potentialKnightMoves

//The bishop, rook, and queen are sliding pieces, so the potential destination logic they have will be 
//different than the king and knight
void Board::potentialBishopMoves(uint64_t bishops){

    uint64_t bishopCopy = bishops;
    bishopMovement = 0;

    //We will shift the bishop bitboard diagonally 7 times in four directions to ensure all possible
    //squares are reached
    for(int i = 0; i < 7; i++){

        bishopCopy = shiftUp(bishopCopy);
        bishopCopy = shiftRight(bishopCopy);
        bishopMovement |= bishopCopy;

    }//end for loop

    bishopCopy = bishops;

    for(int i = 0; i < 7; i++){

        bishopCopy = shiftUp(bishopCopy);
        bishopCopy = shiftLeft(bishopCopy);
        bishopMovement |= bishopCopy;

    }//end for loop

    bishopCopy = bishops;

    for(int i = 0; i < 7; i++){

        bishopCopy = shiftDown(bishopCopy);
        bishopCopy = shiftLeft(bishopCopy);
        bishopMovement |= bishopCopy;

    }//end for loop

    bishopCopy = bishops;

    for(int i = 0; i < 7; i++){

        bishopCopy = shiftDown(bishopCopy);
        bishopCopy = shiftRight(bishopCopy);
        bishopMovement |= bishopCopy;

    }//end for loop


}//end potentialBishopMoves

void Board::potentialRookMoves(uint64_t rooks){

    uint64_t rookCopy = rooks;
    rookMovement = 0;

    for(int i = 0; i < 7; i++){

        rookCopy = shiftUp(rookCopy);
        rookMovement |= rookCopy;

    }//end for loop

    rookCopy = rooks;

    for(int i = 0; i < 7; i++){

        rookCopy = shiftDown(rookCopy);
        rookMovement |= rookCopy;

    }//end for loop

    rookCopy = rooks;

    for(int i = 0; i < 7; i++){

        rookCopy = shiftLeft(rookCopy);
        rookMovement |= rookCopy;

    }//end for loop

    rookCopy = rooks;

    for(int i = 0; i < 7; i++){

        rookCopy = shiftRight(rookCopy);
        rookMovement |= rookCopy;

    }//end for loop

}//end potentialRookMoves

//For the queens, we simply must do everything a rook and bishop can do in terms of movement
void Board::potentialQueenMoves(uint64_t queens){

    uint64_t queenCopy = queens;
    queenMovement = 0;

    for(int i = 0; i < 7; i++){

        queenCopy = shiftUp(queenCopy);
        queenMovement |= queenCopy;

    }//end for loop

    queenCopy = queens;

    for(int i = 0; i < 7; i++){

        queenCopy = shiftDown(queenCopy);
        queenMovement |= queenCopy;

    }//end for loop

    queenCopy = queens;

    for(int i = 0; i < 7; i++){

        queenCopy = shiftLeft(queenCopy);
        queenMovement |= queenCopy;

    }//end for loop

    queenCopy = queens;

    for(int i = 0; i < 7; i++){

        queenCopy = shiftRight(queenCopy);
        queenMovement |= queenCopy;

    }//end for loop

    queenCopy = queens;

    for(int i = 0; i < 7; i++){

        queenCopy = shiftUp(queenCopy);
        queenCopy = shiftLeft(queenCopy);
        queenMovement |= queenCopy;

    }//end for loop

    queenCopy = queens;

    for(int i = 0; i < 7; i++){

        queenCopy = shiftUp(queenCopy);
        queenCopy = shiftRight(queenCopy);
        queenMovement |= queenCopy;

    }//end for loop

    queenCopy = queens;

    for(int i = 0; i < 7; i++){

        queenCopy = shiftDown(queenCopy);
        queenCopy = shiftRight(queenCopy);
        queenMovement |= queenCopy;

    }//end for loop

    queenCopy = queens;

    for(int i = 0; i < 7; i++){

        queenCopy = shiftDown(queenCopy);
        queenCopy = shiftLeft(queenCopy);
        queenMovement |= queenCopy;

    }//end for loop

}//end potentialQueenMoves


