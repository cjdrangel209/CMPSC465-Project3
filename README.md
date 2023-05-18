# CMPSC465-Project3
Takes in a file that has a number that lists the dimensions of a board that contains X's and O's. Any group of O's that is surrounded by X's gets converted to an X. If an O or group of O's is not surrounded by an X's on all sides (i.e. an O that lies along an edge), than it stays as an O.

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
For example, for the following board,
X X X X
X O O X
X X O X
X O X X
After capturing all regions, the board becomes
X X X X
X X X X
X X X X
X O X X
The algorithm should take an input file, named “input.txt”, and output the resulting board in the console.
