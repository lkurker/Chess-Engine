//main.cpp

#include "board.h"
#include "piece.h"
#include "rules.h"
#include <cstdint>

int main(){

    /*

    //std::string color;
    std::string startPos;
    std::string endPos;

    

    //std::cout << "Please input the piece color! ";
    //std::cin >> color;
    //std::cout << "" << std::endl;

    bool keepGoing = true;
    Rules r;

    
    while(keepGoing){

        std::cout << "Please input the start position! ";
        std::cin >> startPos;
        std::cout << "" << std::endl;

        std::cout << "Please input the end position! ";
        std::cin >> endPos;
        std::cout << "" << std::endl;

        
        bool legalMove = r.isValidMovement("k", startPos, endPos, "white");

        if(legalMove == true){

            std::cout << "Good move!" << std::endl;

        }//end if statement

        else if(legalMove == false){

            std::cout << "You're kidding me right?" << std::endl;

        }//end if statement

        std::cout << "Continue? 1 is yes 2 is no: ";
        std::string userInput;
        std::cin >> userInput;
        std::cout << "" << std::endl;

        if(userInput == "1"){

            keepGoing = true;

        }//end if statement

        else{

            keepGoing = false;

        }//end else statement

    }//end while loop

    */

    uint64_t x = 0b0000;

    //Turning on a bit
    x = x | (1ULL << 5);
    x = x | (1ULL << 7);
    x = x | (1ULL << 3);
    x = x | (1ULL << 0);



    /*
    //Checking if a bit is on
    if(x & (1ULL << 2)){

        std::cout << "Bit is on!" << std::endl;

    }

    else{

        std::cout << "Bit is not on!" << std::endl;

    }

    */

    uint64_t board = 0;

    
    board = board | (1ULL << 35);
    board = board | (1ULL << 62);
    
    Board b;
    
    board = b.setSquare(board, "b1");
    b.displayBoard(board);
    

    return 0;

}//end main
