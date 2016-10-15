/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

...Q....
......Q.
..Q.....
.......Q
.Q......
....Q...
Q.......
.....Q..

Hide Tags Backtracking
*/

class Solution {
public:
    int totalNQueens(int n) {
        if(n <= 0)
            return 0;
        int total = 0;
        int col_Val[n];
        memset(col_Val, -1, sizeof(int)*n);
        totalNQueensHelper(n, 0, col_Val, total);
        return total;
    }
    
    void totalNQueensHelper(int n, int row, int* col_Val, int &total){
        if(row == n){
            total++;
            return;
        }
        
        for(int c = 0; c < n; c++){
            if(isValid(row, c, col_Val)){
                col_Val[row] = c;
                totalNQueensHelper(n, row + 1, col_Val, total);
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
