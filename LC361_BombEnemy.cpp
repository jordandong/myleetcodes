/*
TBD
We have a 2D grid. Each cell is either a wall, an enemy or empty.

For example (0-empty, X-enemy, Y-wall):
0 X 0 0
X 0 Y X
0 X 0 0
You have one bomb and you want to kill as many as possible enemies with it.
The bomb will kill all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.

Given such a grid, return the maximum enemies you can kill with one bomb.
Note that you can only put the bomb at empty cell.

In the example, if you put a bomb at (1,1) you will kill 3 enemies which is the best you can get. You can not kill the guy behind the wall at (1,3).
*/

