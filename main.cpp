//main.cpp

#include "board.h"
#include "piece.h"
#include "rules.h"

int main(){

    

    //Board b;
    //b.displayBoard();

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

    

    

    return 0;

}//end main