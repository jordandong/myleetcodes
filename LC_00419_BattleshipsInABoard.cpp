/*
Given an 2D board, count how many different battleships are in it.
The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
1. You receive a valid board, made of only battleships or empty slots.
2. Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.

Example:
X..X
...X
...X
In the above board there are 2 battleships.

Invalid Example:
...X
XXXX
...X
This is not a valid board - as battleships will always have a cell separating between them.

Your algorithm should not modify the value of the board.
*/

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        int M = board.size();
        if (M == 0)
            return res;
        int N = board[0].size();
        if (N == 0)
            return res;
        for (int x = 0; x < M; x++) {
            for (int y = 0; y < N; y++) {
                if ((board[x][y] == '.') ||
                    (x > 0 && board[x - 1][y] == 'X') ||
                    (y > 0 && board[x][y - 1] == 'X'))
                    continue;
                res++;
            }
        }
        return res;
    }
};
