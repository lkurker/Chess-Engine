//board.h

#ifndef BOARD_H_EXISTS
#define BOARD_H_EXISTS

#include <iostream>
#include <vector>


class Board{


    private:

        uint64_t A_FILE = 0;
        uint64_t H_FILE = 0;
        uint64_t kingMovement = 0;
        uint64_t knightMovement = 0;
        uint64_t bishopMovement = 0;
        uint64_t rookMovement = 0;
        uint64_t queenMovement = 0;

        uint64_t whitePawns = 0;
        uint64_t whiteBishops = 0;
        uint64_t whiteKnights = 0;
        uint64_t whiteRooks = 0;
        uint64_t whiteQueens = 0;
        uint64_t whiteKing = 0;

        uint64_t blackPawns = 0;
        uint64_t blackBishops = 0;
        uint64_t blackKnights = 0;
        uint64_t blackRooks = 0;
        uint64_t blackQueens = 0;
        uint64_t blackKing = 0;

        uint64_t whitePieces = 0;
        uint64_t blackPieces = 0;

        uint64_t occupied = 0;
        uint64_t empty = 0;

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
        uint64_t getKingMovement();
        uint64_t getKnightMovement();
        uint64_t getBishopMovement();
        uint64_t getRookMovement();
        uint64_t getQueenMovement();
        uint64_t getWhitePawns();
        uint64_t getWhiteKnights();
        uint64_t getWhiteBishops();
        uint64_t getWhiteRooks();
        uint64_t getWhiteQueens();
        uint64_t getWhiteKing();
        uint64_t getBlackPawns();
        uint64_t getBlackKnights();
        uint64_t getBlackBishops();
        uint64_t getBlackRooks();
        uint64_t getBlackQueens();
        uint64_t getBlackKing();
        uint64_t getWhitePieces();
        uint64_t getBlackPieces();
        uint64_t getOccupied();
        uint64_t getEmpty();
        void potentialKingMoves(uint64_t kings);
        void potentialKnightMoves(uint64_t knights);
        void potentialBishopMoves(uint64_t bishops);
        void potentialRookMoves(uint64_t rooks);
        void potentialQueenMoves(uint64_t queens);
        



};//end class definition

#endif
