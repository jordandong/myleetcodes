/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Hide Tags Array
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int M = board.size();
        if (M == 0)
            return;
        int N = board[0].size();
        if (N == 0)
            return;
        int cur = 1; 
        int next = (cur << 1);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                int cnt = 0;
                for (int x = max(i - 1, 0); x < min(i + 2, M); x++)
                    for (int y = max(j - 1, 0); y < min(j + 2, N); y++)
                        cnt += board[x][y] & cur; // cur cell is counted
                if (cnt - board[i][j] == 3 || cnt == 3) //board[i][j] is not updated yet and 1 vs 3, 0 vs 3 || 1 vs 2
                    board[i][j] |= next;
            }
        }
        
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                board[i][j] >>= 1;
    }
};
