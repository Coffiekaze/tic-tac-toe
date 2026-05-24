#include "opponentnUser.h"
#include "board.h"
#include <iostream>
#include <vector>

int main(){
std::vector<std::pair<int,int>>storedindex;
char response;
std::cout<<"would you like to be x or O"<<std::endl;
std::cin>>response;
std::pair<int,int>twonumbers;
if(response=='x' || response=='X'){
OPP::getinstance().getCharacter()='O'; 
Human::getinstance().getCharacter()='X';
}
else{
OPP::getinstance().getCharacter()='X'; 
Human::getinstance().getCharacter()='O';
}
std::cout<<OPP::getinstance().getname()<<": "<<"your letter is  "<<OPP::getinstance().getCharacter()<<std::endl;
std::cout<<Human::getinstance().getname()<<":"<<"my letter is "<<Human::getinstance().getCharacter()<<std::endl;
std::cout<<"press c to start the game"<<std::endl;
std::cin>>response;
if(response=='c'){
clearScreen();
do{
std::cout<<"To make a move, simply enter two numbers: the row (0-2) and the column (0-2) of the square you want to mark."<<std::endl; 
std::cout<<"make your move"<<std::endl;
Human::getinstance().makemove(Board::getboard());
clearScreen();
displayboard(Board::getboard());
storedindex=OPP::getinstance().getmove(Board::getboard());
std::cout<<"The move you made was at index "<<storedindex[0].first<<" and "<<storedindex[0].second<<std::endl;
minimax(Board::getboard());
}while(winsituation(Board::getboard())==false);



}

return 0; 
}
