/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 
Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
*/

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(word.length() == 0)
            return true;
        int M = board.size(); 
        if(M == 0)
            return false;
        int N = board[0].size();
        if(N == 0)
            return false;
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                if(exsitHelper(i, j, 0, board, word))
                    return true;
        return false;
    }
    
    bool exsitHelper(int r, int c, int k, vector<vector<char> > &board, string &word){
        if(k == word.length())
            return true;
        int M = board.size();
        int N = board[0].size();
        if(r < 0 || r == M || c < 0 || c == N)
            return false;
        
        char t = board[r][c];
        if(t != word[k])
            return false;
        
        board[r][c] = '.';
        if(exsitHelper(r + 1, c, k + 1, board, word)
        || exsitHelper(r - 1, c, k + 1, board, word)
        ||exsitHelper(r, c + 1, k + 1, board, word)
        || exsitHelper(r, c - 1, k + 1, board, word)){
            board[r][c] = t;
            return true;
        }
        board[r][c] = t;
        return false;
    }
};

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(word.length() == 0)
            return true;
        int M = board.size(); 
        if(M == 0)
            return false;
        int N = board[0].size();
        if(N == 0)
            return false;
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                if(exsitHelper(i, j, 0, board, word))
                    return true;
        return false;
    }
    
    bool exsitHelper(int r, int c, int k, vector<vector<char> > &board, string &word){
        if(k == word.length())
            return true;
        
        int M = board.size();
        int N = board[0].size();
        if(r < 0 || r == M || c < 0 || c == N)
            return false;
        
        char t = board[r][c];
        if(t != word[k])
            return false;
        
        board[r][c] = '.';
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto d : dir) {
            int x = r + d[0], y = c + d[1];
            if (exsitHelper(x, y, k + 1, board, word)) {
                board[r][c] = t;
                return true;
            }
        }
        board[r][c] = t;
        return false;
    }
};
