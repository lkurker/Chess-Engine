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

        void displayBoard();
        std::vector<std::vector<std::string>>& getBoard();

        



};//end class definition

#endif
