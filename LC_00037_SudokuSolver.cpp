/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

53..7....    
6..195...   
.98....6.
8...6...3
4..8.3..1
7...2...6
.6....28.
...419..5
....8..79
A sudoku puzzle...

534678912
672195348
198342567
859761423
426853791
713924856
961537284
287419635
345286179
...and its solution numbers marked in red.

Hide Tags Backtracking Hash Table
*/

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        int M = board.size();
        if (M == 0 || M != 9)
            return;
        int N = board[0].size();
        if (N != M)
        	return;

        int unfilled = 81;
        int row[9], col[9], blk[9];
        memset(row, 0, sizeof(int)*9);
        memset(col, 0, sizeof(int)*9);
        memset(blk, 0, sizeof(int)*9);
        
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] != '.'){
                    int bit = 1<<(board[i][j] - '0');
                    row[i] |= bit; //row
                    col[j] |= bit; //coloumn
                    blk[i/3*3 + j/3] |= bit; //block
                    unfilled--;
                }
            }
        }
        solveSudokuHelper(board, row, col, blk, 0, 0, unfilled);
    }
    
    bool solveSudokuHelper(vector<vector<char> > &board, int row[], int col[], int blk[], int x, int y, int unfilled){
        if(unfilled == 0)
            return true;
        int M = board.size();
        for(int i = x; i < M; i++){
            int j = y;
            if(i != x)
                j = 0;
            for(; j < M; j++){
                if(board[i][j] == '.'){
                    for(int k = 1; k <= 9; k++){
                        int bit = 1<<k;
                        if((row[i] & bit)  || (col[j] & bit) || (blk[i/3*3 + j/3] & bit))//check validation
                            continue;
                        board[i][j] = (char)('0' + k);
                        row[i] |= bit;
                        col[j] |= bit;
                        blk[i/3*3 + j/3] |= bit;
                        if(solveSudokuHelper(board, row, col, blk, i, j, unfilled -1))
                            return true;
                        board[i][j] = '.';
                        row[i] ^= bit;
                        col[j] ^= bit;
                        blk[i/3*3 + j/3] ^= bit;
                    }
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solve(board, 0, 0);
    }

    bool solve(vector<vector<char> > &board, int row, int col) {
        bool res = getNextEmpty(board, row, col);
        if (!res)
        	return true;
        vector<char> possible;
        getPossibleValues(board, possible, row, col);
        if (possible.size() == 0)
        	return false;
        for (int i = 0; i < possible.size(); i++) {
            board[row][col] = possible[i];
            if (solve(board, row, col))
            	return true;
            board[row][col] = '.';
        }
        return false;
    }

    bool getNextEmpty(vector<vector<char> > &board, int &row, int &col) {
        while (row <= 8 && col <= 8) {
            if (board[row][col] == '.')
            	return true;
            row = (col == 8) ? row + 1 : row;
            col = (col == 8) ? 0 : col + 1;
        }
        return false;
    }

    void getPossibleValues(vector<vector<char> > &board, vector<char> &possible, int row, int col) {
        bool s[9] = { false };
        for (int i = 0; i < 9; i++) {
            if (board[row][i] != '.')
            	s[board[row][i]-'1'] = true;
            if (board[i][col] != '.')
            	s[board[i][col]-'1'] = true;
            char c = board[row/3*3+i/3][col/3*3+i%3];
            if (c!='.')
            	s[c-'1'] = true;
        }
        for (int i = 0; i < 9; i++) {
            if (!s[i])
            	possible.push_back('1'+i);
        }
    }
};
