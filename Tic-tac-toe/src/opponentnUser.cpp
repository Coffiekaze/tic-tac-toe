#include "opponentnUser.h"
#include <board.h>
#include <iostream> 
#include <vector> 

//to help the AI remember and record which moves on the board are not its own
std::vector<std::pair<int,int>>OPP::getmove(std::vector<std::vector<char>>&boardmove){
  std::vector<std::pair<int,int>>AIstorage;
  std::pair<int,int>Rememberme;
   for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(boardmove[i][j]==Human::getinstance().getCharacter()){
        Rememberme.first=i;
        Rememberme.second=j;
        AIstorage.push_back(Rememberme);
      }
  }
}
return OPP::getinstance().getmemory()=AIstorage;
}
std::vector<std::pair<int,int>>Human::getmove(std::vector<std::vector<char>>&boardmove){
  std::vector<std::pair<int,int>>Humansparestoage;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(boardmove[i][j]==OPP::getinstance().getCharacter())
      return Humansparestoage;
  }
}
 return Human::getinstance().getMemory()=Humansparestoage;
}

OPP& OPP::getinstance(){
  static OPP AI("AI",'x'); 
  return AI;
}
  
Human& Human::getinstance(){
  static Human player1("Player1",'O'); 
  return player1;
}

void Human::makemove(std::vector<std::vector<char>>&boardmove){
  std::pair<int,int>moveset;
  std::cin>>moveset.first>>moveset.second;
  boardmove[moveset.first][moveset.second]=Human::getinstance().getCharacter();

}

void OPP::makemove(std::vector<std::vector<char>>&boardmove){
  std::pair<int,int>moveset;
  std::cin>>moveset.first>>moveset.second;
  boardmove[moveset.first][moveset.second]=OPP::getinstance().getCharacter();
}

void OPP::makemoveAI(std::pair<int,int>move,std::vector<std::vector<char>>&boardmove){
    boardmove[move.first][move.second]=OPP::getinstance().getCharacter();
}
//this is for winning a game of tic-tac-toe 
bool winsituation(const std::vector<std::vector<char>>& boardmove) {
    char human = Human::getinstance().getCharacter();
    char ai    = OPP::getinstance().getCharacter();

    // 1) Check each row for a win
    for (int i = 0; i < 3; ++i) {
        // Human win on row i?
        if (boardmove[i][0] == human &&
            boardmove[i][1] == human &&
            boardmove[i][2] == human)
        {
            std::cout << "You have won!\n";
            return true;
        }
        // AI win on row i?
        if (boardmove[i][0] == ai &&
            boardmove[i][1] == ai &&
            boardmove[i][2] == ai)
        {
            std::cout << "You have lost!\n";
            return false;
        }
    }

    // 2) Check each column for a win
    for (int j = 0; j < 3; ++j) {
        // Human win on column j?
        if (boardmove[0][j] == human &&
            boardmove[1][j] == human &&
            boardmove[2][j] == human)
        {
            std::cout << "You have won!\n";
            return true;
        }
        // AI win on column j?
        if (boardmove[0][j] == ai &&
            boardmove[1][j] == ai &&
            boardmove[2][j] == ai)
        {
            std::cout << "You have lost!\n";
            return false;
        }
    }

    // 3) Check the two diagonals
    // Top-left → bottom-right
    if (boardmove[0][0] == human &&
        boardmove[1][1] == human &&
        boardmove[2][2] == human)
    {
        std::cout << "You have won!\n";
        return true;
    }
    if (boardmove[0][0] == ai &&
        boardmove[1][1] == ai &&
        boardmove[2][2] == ai)
    {
        std::cout << "You have lost!\n";
        return false;
    }

    // Top-right → bottom-left
    if (boardmove[0][2] == human &&
        boardmove[1][1] == human &&
        boardmove[2][0] == human)
    {
        std::cout << "You have won!\n";
        return true;
    }
    if (boardmove[0][2] == ai &&
        boardmove[1][1] == ai &&
        boardmove[2][0] == ai)
    {
        std::cout << "You have lost!\n";
        return false;
    }

    // 4) Check for draw (board full, no winner)
    bool full = true;
    for (int i = 0; i < 3 && full; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (boardmove[i][j] == ' ') {
                full = false;
                break;
            }
        }
    }
    if (full) {
        std::cout << "Draw!\n";
    }

    // If we get here, there's no win yet (and possibly no draw either)
    return false;
}

int evaluate(const std::vector<std::vector<char>>& board) {
    // Check all rows and columns
    for(int i = 0; i < 3; ++i) {
        // Row i
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2]) 
        {
            if(board[i][0] == 'O') return +1;
            if(board[i][0] == 'X') return -1;
        }
        // Column i
        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i]) 
        {
            if(board[0][i] == 'O') return +1;
            if(board[0][i] == 'X') return -1;
        }
    }

    // Check the two diagonals
    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2]) 
    {
        if(board[0][0] == 'O') return +1;
        if(board[0][0] == 'X') return -1;
    }
    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0]) 
    {
        if(board[0][2] == 'O') return +1;
        if(board[0][2] == 'X') return -1;
    }

    // No winner yet (either draw or still in progress)
    return 0;
}
     
//implementing the minimax algorithm
void minimax(std::vector<std::vector<char>>& Boardgame) {
    // 1) record the human’s latest move
    OPP::getinstance().getmove(Boardgame);
    auto &mem = OPP::getinstance().getmemory();
    if (mem.empty()) return;                  // sanity
    auto [oppRow, oppCol] = mem.back();       // unpack last X

    // 2) search for the best O to play
    int bestScore = -1000;
    std::pair<int,int> bestMove{-1,-1};

    // a) loop every cell
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        // b) only try empty cells
        if (Boardgame[i][j] != ' ')
          continue;
        // c) skip exactly where they just played
        if (i == oppRow && j == oppCol)
          continue;

        // simulate placing O at (i,j)
        auto boardCopy = Boardgame;
        boardCopy[i][j] = 'O';

        // simulate their best “minimize” reply
        int worstReply = +1000;
        for (int pi = 0; pi < 3; ++pi) {
          for (int pj = 0; pj < 3; ++pj) {
            if (boardCopy[pi][pj] == ' ') {
              auto reply = boardCopy;
              reply[pi][pj] = 'X';
              worstReply = std::min(worstReply, evaluate(reply));
            }
          }
        }

        // pick the move whose worst reply is highest
        if (worstReply > bestScore) {
          bestScore = worstReply;
          bestMove  = {i, j};
        }
      }
    }

    // 3) play exactly one move and exit
    if (bestMove.first != -1) {
      OPP::getinstance().makemoveAI(bestMove, Boardgame);
    }
    displayboard(Boardgame);
}
