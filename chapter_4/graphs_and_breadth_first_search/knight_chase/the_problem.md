# Problem 1: _Knight Chase_

### The problem

This problem concerns two players, a pawn and a knight, playing a board game. (Don't worry: you don't need to know
anything about chess.)  
&nbsp;&nbsp; The board has _**r**_ rows, with row 1 at the bottom and row _**r**_ at the top. The board has _**c**_
columns, with column 1 at the left and column _**c**_ at the right.  
&nbsp;&nbsp; The pawn and knight each start in some square of the board. The pawn moves first, then the knight moves,
then the pawn, then the knight, and so on, until the game ends. For each turn, a move must be made: remaining at the
current square is not an option.  
&nbsp;&nbsp; The pawn has no choice on what move to make: for each of its turns, it moves up one square.  
&nbsp;&nbsp; The knight, by contrast, has up to eight choice for each move:

- Up 1, right 2
- Up 1, left 2
- Down 1, right 2
- Down 1, left 2
- Up 2, right 1
- Up 2, left 1
- Down 2, right 1
- Down 2, left 1

I say "up to eight choices," not "exactly eight choices," because moves that bring the knight outside of the board are
not allowed. For example, if the board has 10 columns and the knight is in column 9, then no move that takes the knight
two columns to the right is allowed.  
&nbsp;&nbsp; The following diagram shows the knight's available moves:  

|   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|
|   |   | f |   | e |   |   |
|   | b |   |   |   | a |   |
|   |   |   | K |   |   |   |
|   | d |   |   |   | c |   |
|   |   | h |   | g |   |   |
|   |   |   |   |   |   |   |

Here, the knight is represented as K, and each letter from a to h represents one of its possible moves.  
&nbsp;&nbsp; The game ends when one of three things happens: the knight wins, the game is a stalemate (that is, a tie),
or the knight loses.  
- The knight wins if the knight makes a move and lands on the same square as the pawn before the pawn reaches the top
row. To win, the knight has to be the one to make move; if the pawn makes a move and lands on the knight, this doesn't
count as the knight winning.
- The game is stalemate if the knight makes a move and lands on the square above the pawn before tha pawn reaches the
top row. Again, the knight has to be the one to make this move; the only exception is that the game can start as a 
stalemate if the knight starts one square above the pawn.
- The knight loses if the pawn reaches the top row before the knight wins or the game is a stalemate. That is, if the
pawn gets to the top row before the knight lands on it or lands on the square above it, then the knight loses. Once the
pawn reaches te top row, the knight is not allowed to move anymore.

&nbsp;&nbsp; The goal is to determine the best-case of test outcome for the knight and the number of knight moves
required to produce that outcome.
---
#### Input
The first line of input gives the number of test cases that will follow. Each test case consists of six lines:

- The number of rows in the board, between 3 and 99.
- The number of columns in the board, between 3 and 99.
- The starting row of the pawn.
- The starting column of the pawn.
- The starting row of the knight.
- The starting column of the knight.

It's guaranteed that the pawn and knight will have different starting positions and that the knight starts at a position
where it has at least one available move.
---
#### Output
For each test case, output a line with one of three messages:
- If the knight can win, output  
_Win in **m** knight move(s)._
- If the knight cannot win but can cause a stalemate, output  
_Stalemate in **m** knight move(s)._
- If the knight cannot win or cause a stalemate, output  
_Loss in **m** knight move(s)._

Here, **m** is the minimum number of moves made by the knight.
The time limit for solving the test cases is two seconds.
