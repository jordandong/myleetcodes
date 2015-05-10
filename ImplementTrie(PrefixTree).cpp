/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

Hide Tags Data Structure Trie
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

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *t = root;
        for (int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'a'; 
            if (t->node[idx] == NULL) 
                t->node[idx] = new TrieNode();
            if(i == s.length() - 1) // the end of insert
                t->is_end[idx] = true;
            t = t->node[idx];
        }
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *t = root;
        for (int i = 0; i < key.length(); i++) {
            int idx = key[i] - 'a'; 
            if (NULL == t->node[idx])
                return false;
            if (i == key.length() - 1) //check the end
                return t->is_end[idx];
            t = t->node[idx];
        }
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *t = root;
        for (int i = 0; i < prefix.length(); i++) {
            int idx = prefix[i] - 'a'; 
            if (NULL == t->node[idx])
                return false;
            t = t->node[idx];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
