/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

...Q....
......Q.
..Q.....
.......Q
.Q......
....Q...
Q.......
.....Q..

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

Hide Tags Backtracking
*/

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        if(n <= 0)
            return res;
        vector<string> sol(n, string(n, '.'));
        int col_Val[n];
        memset(col_Val, -1, sizeof(int)*n);
        solveNQueensHelper(n, 0, col_Val, sol, res);
        return res;
    }
    
    void solveNQueensHelper(int n, int row, int* col_Val, vector<string> &sol, vector<vector<string> > &res){
        if(row == n){
            res.push_back(sol);
            return;
        }
        
        for(int c = 0; c < n; c++){
            if(isValid(row, c, col_Val)){
                col_Val[row] = c;
                sol[row][c] = 'Q';
                solveNQueensHelper(n, row + 1, col_Val, sol, res);
                sol[row][c] = '.';
            }
        }
    }
    
    bool isValid(int row, int col, int *col_Val){
        for(int r = row - 1; r >= 0; r--){
            if(row - r == abs(col - col_Val[r]) || col == col_Val[r])
                return false;
        }
        return true;
    }
};
