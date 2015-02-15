/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

Hide Tags Array Backtracking
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
        if(r <0 || r == M || c<0 || c == N)
            return false;
        
        char t = board[r][c];
        if(t != word[k])
            return false;
        
        board[r][c] = '.';
        if(exsitHelper(r + 1, c, k + 1, board, word))
            return true;
        if(exsitHelper(r - 1, c, k + 1, board, word))
            return true;
        if(exsitHelper(r, c + 1, k + 1, board, word))
            return true;
        if(exsitHelper(r, c - 1, k + 1, board, word))
            return true;
        board[r][c] = t;
        return false;
    }
};
