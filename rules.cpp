//rules.cpp

#include "rules.h"


bool Rules::isValidMovement(std::string pieceName, std::string startPos, std::string endPos, std::string color){


    //We will first convert the start and end positions to their own integers in order to compare them to one another
    int startCol = startPos[0] - 'a' + 1;
    int startRow = startPos[1] - '0';
    int endCol = endPos[0] - 'a' + 1;
    int endRow = endPos[1] - '0';


    //Before we check anything else, we must ensure that the start and end positions are correctly on the board
    if(startCol > 8 || startCol < 1 || startRow > 8 || startRow < 1 || endCol > 8 || endCol < 1 || endRow > 8 || endRow < 1){

        return false;

    }//end if statement


    //We also need to ensure that a move was actually made
    if((startCol == endCol) && (startRow == endRow)){

        return false;

    }//end if statement


    //Now we will input the movement rules for each of the pieces. We will begin with the pawns
    if(pieceName == "p" || pieceName == "P"){


        //Since pawns can only move forward, we must first check to see if they're white or black
        if(color == "white"){

            //A pawn can move forward one or two spaces forward, or one space forward diagonally if they're taking a piece
            if((((startRow + 1) == endRow) || ((startRow + 2) == endRow)) && (startCol == endCol)){

                return true;

            }//end if statement

            else if(((startRow + 1) == endRow) && (((startCol - 1) == endCol) || ((startCol + 1) == endCol))){

                return true;

            }//end else if statement

        }//end if statement


        else if(color == "black"){


            if((((startRow - 1) == endRow) || ((startRow - 2) == endRow)) && (startCol == endCol)){

                return true;

            }//end if statement

            else if(((startRow - 1) == endRow) && (((startCol - 1) == endCol) || ((startCol + 1) == endCol))){

                return true;

            }//end else if statement


        }//end else if statement



    }//end if statement


    //Now for the bishop, which moves diagonally in any direction
    else if(pieceName == "b" || pieceName == "B"){

        if(abs(endCol - startCol) == abs(endRow - startRow)){

            return true;

        }//end if statement        


    }//end else if statement

    
    //For the knight, it moves in an L shape
    else if(pieceName == "n" || pieceName == "N"){

        if(((abs(endCol - startCol) == 2) && (abs(endRow - startRow) == 1)) || ((abs(endCol - startCol) == 1) && (abs(endRow - startRow) == 2))){

            return true;

        }//end if statement

    }//end else if statement


    //The rook can move in a straight line horizontally or vertically
    else if(pieceName == "r" || pieceName == "R"){

        if(((startCol == endCol) && (startRow != endRow)) || ((startCol != endCol) && (startRow == endRow))){

            return true;

        }//end if statement

    }//end else if statement


    //Queens can move in the same way as a bishop or rook
    else if(pieceName == "q" || pieceName == "Q"){

        if((abs(endCol - startCol) == abs(endRow - startRow)) || ((startCol == endCol) && (startRow != endRow)) || ((startCol != endCol) && (startRow == endRow))){

            return true;

        }//end if statement

    }//end else if statement

    //Kings can move in any one direction
    else if(pieceName == "k" || pieceName == "K"){

        if(((abs(endCol - startCol) == 1) || (abs(endRow - startRow) == 1)) && ((abs(endCol - startCol) < 2) && (abs(endRow - startRow) < 2))){

            return true;

        }//end if statement

    }//end else if statement

    return false;

}//end legalMovement