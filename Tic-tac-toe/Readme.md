Tic-Tac-Toe Game
This project implements a simple command-line Tic-Tac-Toe where you (X) play against an AI (O) using Minimax.

Building the Game:

Make sure you have a C++17 compiler (e.g. g++).

From the project root, run:
make all
This will compile everything and put the executable in output/.

Running the Game:

To build and run in one step, type:
make run

Or manually launch:

- **macOS / Linux:**
  ```bash
  ./output/main
  ```
- **Windows:**
  ```bash
  output\main.exe
  ```

How to Play:

The board’s rows and columns are both numbered 0, 1, 2.

Each turn you enter two numbers (row then column), separated by a space, to place your X.
For example:
1 2
will put your X in row 1, column 2 (middle row, right column).

The AI will then place an O optimally.

Play continues until someone wins or the board fills (a draw).