/*
Design a data structure that supports the following two operations:
void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note:
You may assume that all words are consist of lowercase letters a-z.

click to show hint.
You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.

Hide Tags Depth-first Search Data Structure Trie
*/

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode *node[26];
    bool is_end[26];
    TrieNode() {
        memset(node, 0, sizeof(node));
        memset(is_end, 0, sizeof(is_end));
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *t = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a'; 
            if (t->node[idx] == NULL) 
                t->node[idx] = new TrieNode();
            if(i == word.length() - 1) // the end of insert
                t->is_end[idx] = true;
            t = t->node[idx];
        }
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if(word.length() == 0)
            return true;
        return search_helper(word, 0, root);
    }
    
    bool search_helper(string &s, int start, TrieNode* tnode){
        if(start == s.length())
            return true;
        if(s[start] == '.'){
            for (int i = 0; i < 26; i++) {
                if(tnode->node[i] && search_helper(s, start + 1, tnode->node[i])) {
                    if (start == s.length() - 1 && tnode->is_end[i] == false)
                        continue;
                    return true;
                }
            }
            return false;
        } else {
            int idx = s[start] - 'a'; 
            if (NULL == tnode->node[idx])
                return false;
            if (start == s.length() - 1) //check the end
                return tnode->is_end[idx];
            return search_helper(s, start + 1, tnode->node[idx]);
        }
    }
private:
    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
