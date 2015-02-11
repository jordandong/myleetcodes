/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules(http://sudoku.com.au/TheRules.aspx).

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

53..7....    
6..195...   
.98....6.
8...6...3
4..8.3..1
7...2...6
.6....28.
...419..5
....8..79
A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

Hide Tags Hash Table
*/

//using bits, T: O(N^2) S: O(3)
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int M = board.size();
        if (M == 0 || M != 9)
            return false;
        int N = board[0].size();
        if (N != M)
        	return false;

        for (int i = 0; i < M; i++) {
            int row = 0, col = 0, blk = 0;
            for (int j = 0; j < N; j++) {
                int r, c, bit;
                //check row
                if(board[i][j] != '.'){
                    bit = 1<<(board[i][j] - '0');
                    if(row & bit)
                    	return false;
                    row |= bit;
                }
                //check coloumn
                if (board[j][i] != '.') {
                    bit = 1<<(board[j][i] - '0');
                    if(col & bit)
                    	return false;
                    col |= bit;
                }
                //check block
                r = i/3*3 + j/3;
                c = i%3*3 + j%3;
                if (board[r][c] != '.') {
                    bit = 1<<(board[r][c] - '0');
                    if(blk & bit)
                    	return false;
                    blk |= bit;
                }
            }
        }
        return true;
    }
};

//T: O(N^2)  S : O(30)
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int M = board.size();
        if (M == 0 || M != 9)
            return false;
        int N = board[0].size();
        if (N != M)
        	return false;

        bool row[10], col[10], blk[10];
        
        for (int i = 0; i < M; i++) {
            memset(row, false, sizeof(bool) * 10);
            memset(col, false, sizeof(bool) * 10);
            memset(blk, false, sizeof(bool) * 10);
            for (int j = 0; j < N; j++) {
                int r, c, k;
                //check row
                if(board[i][j] != '.'){
                    k = board[i][j] - '0';
                    if(row[k])
                    	return false;
                    row[k] = true;
                }
                //check coloumn
                if (board[j][i] != '.') {
                    k = board[j][i] - '0';
                    if(col[k])
                    	return false;
                    col[k] = true;
                }
                //check block
                r = i/3*3 + j/3;
                c = i%3*3 + j%3;
                if (board[r][c] != '.') {
                    k = board[r][c] - '0';
                    if(blk[k])
                    	return false;
                    blk[k] = true;
                }
            }
        }
        return true;
    }
};

//T: O(3*N^2)  S : O(10)
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int M = board.size();
        if (M == 0 || M != 9)
            return false;
        int N = board[0].size();
        if (N != M)
        	return false;

        bool visited[10];
        // check row
        for (int i = 0; i < M; i++) {
            memset(visited, 0, sizeof(bool) * 10);
            for (int j = 0; j < N; j++) {
                if (board[i][j] != '.') {
                    int k = board[i][j] - '0';
                    if (visited[k])
                    	return false;
                    visited[k] = true;
                }
            }
        }
        // check coloumn
        for (int j = 0; j < N; j++) {
            memset(visited, false, sizeof(bool) * 10);
            for (int i = 0; i < M; i++) {
                if (board[i][j] != '.') {
                    int k = board[i][j] - '0';
                    if (visited[k])
                    	return false;
                    visited[k] = true;
                }
            }
        }
        
        // check block
        for (int i = 0; i < M; i++) {
            memset(visited, false, sizeof(bool) * 10);
            for (int j = 0; j < N; j++) {
                int r = i/3*3 + j/3;
                int c = i%3*3 + j%3;
                if (board[r][c] != '.') {
                    int k = board[r][c] - '0';
                    if (visited[k])
                    	return false;
                    visited[k] = true;
                }
            }
        }
        return true;
    }
};
