Conway's Game of Life :
Game creates table of cells (20x20), dead or alive.
Course of the game is after every tick, detecting how many alive neighbours every cell has 
and making decision if this cell will be unchanged, will die or born.

Initialization of game rules :

1. Open file initialize.txt

2. On existing table u can add starting state of the table by adding cells who will be alive
at the start. To do this put 1 in place of 0.

3. Under the table u can see free lines of numbers, u can chose the rules of the game by adding
numbers in these lines :
- first line are the numbers of alive cells in neighbourhood who will force a cell to be born
- second line are the numbers of alive cells in neighbourhood who will not change o state of cell
- third line are the numbers of alive cells in neighbourhood who will force a cell to die


!! RULES OF EDITING initialize.txt !!
U can't change the format of the file
In starting table there can only be 1 and 0
There can't be empty places in starting table
Behind every character in file there need to bee white character (space, enter)
End point of every line with rule numbers needs to ned with "9"
Numbers in rules of game are numbers from 1 to 8 , every of them needs to occur and can't repeat

Every violation of the rules of editing the startup file will result in the interruption of
the game operation and whole program

