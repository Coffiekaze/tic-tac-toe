#pragma once

#include <iostream>
#include <vector> 




class Player{
public: 
//this is a public class
Player(std::string Playername,char Letter):name(Playername),character(Letter){}
 virtual std::vector<std::pair<int,int>>getmove(std::vector<std::vector<char>>&boardmove)=0;
 virtual void makemove(std::vector<std::vector<char>>&boardmove)=0;
 virtual ~Player() = default;  // always include virtual destructor
 std::string getname(){
    return name; 
 }
 char& getCharacter(){
    return character;
 }
private:
std::string name; 
char character;

};

class OPP:public Player{
public:
OPP(std::string AIname,char AILetter):Player(AIname,AILetter){}
void makemove(std::vector<std::vector<char>>&boardmove);
void makemoveAI(std::pair<int,int>move,std::vector<std::vector<char>>&boardmove);
std::vector<std::pair<int,int>> getmove(std::vector<std::vector<char>>&boardmove)override; 
static OPP& getinstance();
std::vector<std::pair<int,int>>&getmemory(){
   return Memory;
}
private: 
//introducing the storage propery for AI
std::vector<std::pair<int,int>>Memory;
};
 
class Human:public Player{
public:
Human(std::string HumanName,char PlayerLetter):Player(HumanName,PlayerLetter){}
void makemove(std::vector<std::vector<char>>&boardmove);
std::vector<std::pair<int,int>> getmove(std::vector<std::vector<char>>&boardmove)override;
static Human& getinstance();
std::vector<std::pair<int,int>>getMemory(){
   return HumanMemory;
}
private:
std::string PersonName;
char characterHuman;
std::vector<std::pair<int,int>>HumanMemory;
};
void minimax(std::vector<std::vector<char>>&Boardgame);
int evaluate(const std::vector<std::vector<char>>& board);




