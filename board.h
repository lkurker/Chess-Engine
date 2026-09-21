//board.h

#ifndef BOARD_H_EXISTS
#define BOARD_H_EXISTS

#include <iostream>
#include <vector>


class Board{


    private:

        std::vector<std::vector<std::string>> board{8, std::vector<std::string>(8)};

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

        



};//end class definition

#endif
