/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region .

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
*/

class Solution {
public:

    int m;
    int n;
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        m = board.size();
        if(m!=0)
            n= board[0].size();
        
        for(int y=0;y<=n-1;y++){
            visitboard(0, y, board);
            visitboard(m-1, y, board);
        }
        
        for(int x=1;x<m-1;x++){
            visitboard(x, 0, board);
            visitboard(x, n-1, board);
        }
        
         for(int x=0; x<m; x++){
            for(int y=0; y<n; y++){
                if(board[x][y]=='O')
                    board[x][y]='X';
                else if(board[x][y]=='V')
                    board[x][y]='O';
            }
        }
        
    }
    
    void visitboard(int x, int y, vector<vector<char> > &board){
        if(x<0||y<0||x>=m||y>=n||board[x][y]!='O')
            return;
        else{
            board[x][y] = 'V';
            visitboard(x+1, y, board);
            visitboard(x, y+1, board);
            visitboard(x-1, y, board);
            visitboard(x, y-1, board);
        }
        return;
    }
};
