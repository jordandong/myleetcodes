/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Hide Tags Breadth-first Search
*/

class Solution {
private:
    char dummy_char;
public:
    void solve(vector<vector<char>> &board) {
        int M = board.size();
        if(M == 0)
            return;
        int N = board[0].size();
        if(N == 0)
            return;
        
        dummy_char = 'F';
        for(int i = 0; i < M; i++){
            solveHelper(i, 0, board);
            solveHelper(i, N - 1, board);
        }
        for(int j = 0; j < N; j++){
            solveHelper(0, j, board);
            solveHelper(M - 1, j, board);
        }
        
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] == dummy_char)
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    
    //BFS non-recursion, pass all the cases
    void solveHelper(int i, int j, vector<vector<char>> &board){
        stack<pair<int, int> > stk;
        stk.push(make_pair(i, j));
        while(stk.size()){
            int x = stk.top().first;
            int y = stk.top().second;
            stk.pop();
            if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != 'O')
                continue;
            
            board[x][y] = dummy_char;
            stk.push(make_pair(x + 1, y));
            stk.push(make_pair(x - 1, y));
            stk.push(make_pair(x, y + 1));
            stk.push(make_pair(x, y - 1));
        }
    }
};

//BFS recursion, Run Time error, stack overflow
class Solution {
private:
    char dummy_char;
public:
    void solve(vector<vector<char>> &board) {
        int M = board.size();
        if(M == 0)
            return;
        int N = board[0].size();
        if(N == 0)
            return;
        
        dummy_char = 'F';
        for(int i = 0; i < M; i++){
            solveHelper(i, 0, board);
            solveHelper(i, N - 1, board);
        }
        for(int j = 0; j < N; j++){
            solveHelper(0, j, board);
            solveHelper(M - 1, j, board);
        }
        
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] == dummy_char)
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    
    void solveHelper(int i, int j, vector<vector<char>> &board){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O')
            return;
        board[i][j] = dummy_char;
        solveHelper(i + 1, j, board);
        solveHelper(i - 1, j, board);
        solveHelper(i, j + 1, board);
        solveHelper(i, j - 1, board);
    }
};
