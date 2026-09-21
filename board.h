//board.h

#ifndef BOARD_H_EXISTS
#define BOARD_H_EXISTS

#include <iostream>
#include <vector>


class Board{


    private:

        uint64_t A_FILE = 0;
        uint64_t H_FILE = 0;

    public: 

        Board();

        void displayBoard(uint64_t board);
        uint64_t setSquare(uint64_t board, std::string position);
        bool isSquareSet(uint64_t board, std::string position);
        uint64_t clearSquare(uint64_t board, std::string position);
        uint64_t toggleSquare(uint64_t board, std::string position);
        int getPosition(std::string position);
        uint64_t getOccupied(uint64_t whitePieces, uint64_t blackPieces);
        uint64_t getEmpty(uint64_t whitePieces, uint64_t blackPieces);
        uint64_t shiftUp(uint64_t board);
        uint64_t shiftDown(uint64_t board);
        uint64_t shiftLeft(uint64_t board);
        uint64_t shiftRight(uint64_t board);
        uint64_t getA_File();
        uint64_t getH_File();
        



};//end class definition

#endif
