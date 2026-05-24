#include "board.h"
#include <iostream> 
#include  <vector> 
#include <iostream> 

void displayboard(const std::vector<std::vector<char>>&Boardtaker){
    std::cout << "-------------" <<std:: endl;
        for (int i = 0; i < 3; i++) {
           std:: cout << "| ";
            for (int j = 0; j < 3; j++) {
                std::cout << Boardtaker[i][j] << " | ";
            }
            std::cout << std::endl << "-------------" << std::endl;
        }
    }

void clearScreen() {
    // ANSI escape code to clear the screen and move cursor to top-left
    std::cout << "\033[2J\033[1;1H";
}
