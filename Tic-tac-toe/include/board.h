#ifndef BOARD_H
#define BOARD_H

#include <iostream> 
#include <vector> 

class Board {
public:
    std::vector<std::vector<char>> Theboard = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}  
    };

    static std::vector<std::vector<char>>&getboard() {
       static Board Aboard;
        return Aboard.Theboard;
    }

};
//function for displaying the board in a user friendly format 
void clearScreen();

void displayboard (const std::vector<std::vector<char>>&Boardtaker);
bool winsituation(const std::vector<std::vector<char>>& boardmove);
#endif  // BOARD_H