/*
Given a 2D board and a list of words from the dictionary, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].

Note:
You may assume that all inputs are consist of lowercase letters a-z.

click to show hint.
You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?
If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.

Hide Tags Backtracking Trie
*/

//Cannot use board to build trie. There are too manu combinations.
class TrieNode {
public:
    TrieNode *next[26];
    bool word_end;
    
    TrieNode(){
        memset(next, 0, 26*sizeof(TrieNode*));
        word_end = false;
    }
    
    ~TrieNode() {
        for(int i = 0; i < 26; i++){
            if(next[i])
                delete next[i];
        }
    }
    
    void Add(string &s, int idx) {
        if(idx == s.length()){
            word_end = true; // record the end of each word
            return;
        }
        if(next[s[idx] - 'a'] == NULL)
            next[s[idx] - 'a'] = new TrieNode();
        next[s[idx]-'a']->Add(s, idx + 1);
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        TrieNode node; 
        for(int i = 0; i < words.size(); i++) 
            node.Add(words[i], 0);
        
        string sol = "";
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j< board[0].size(); j++)
                findWords(board, &node, i, j, sol, res); 
        return res;
    }
    
    void findWords(vector<vector<char> > &board, TrieNode *node, int i, int j, string &sol,vector<string> &res){
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
             
        if (board[i][j] == '*' || !node->next[board[i][j]-'a'])
            return;
        
        char tmp = board[i][j];
        TrieNode *nextNode = node->next[board[i][j]-'a'];
        sol.push_back(board[i][j]);
        if(nextNode->word_end){
            res.push_back(sol);
            nextNode->word_end = false; // avoid the dup
        }
            
        board[i][j] = '*';
        findWords(board, nextNode, i + 1, j, sol, res);  
        findWords(board, nextNode, i, j + 1, sol, res);  
        findWords(board, nextNode, i - 1, j, sol, res);  
        findWords(board, nextNode, i, j - 1, sol, res);
        board[i][j] = tmp;
        sol.erase(sol.length()-1);
    } 
};
