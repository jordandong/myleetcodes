/*
Implement a magic directory with buildDict, and search methods.

For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.

For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.

Example 1:
Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False
Note:
You may assume that all the inputs are consist of lowercase letters a-z.
For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
Please remember to RESET your class variables declared in class MagicDictionary, as static/class variables are persisted across multiple test cases. Please see here for more details.
*/

class MagicDictionary {
private:
    struct Node {
        struct Node* next[26];
        bool end;
        Node() {
            memset(next, 0, sizeof(next));
            end = false;
        }
    };
    
    struct Node *root;

    void insert (string word) {
        int N = word.length();
        struct Node *cur = root; 
        for (int i = 0; i < N; i++) {
            char c = word[i];
            if (!cur->next[c - 'a']) {
                cur->next[c - 'a'] = new struct Node();
            }
            cur = cur->next[c - 'a'];
        }
        cur->end = true;
    }
    
    bool find (struct Node *cur, string word, int idx, bool mod) {
        if (!cur)
            return false;
        int N = word.length();
        if (idx == N)
            return cur->end && mod;
        char c = word[idx];
        for (int i = 0; i < 26; i++) {
            if (!mod && c != (i + 'a')) {
                if (find (cur->next[i], word, idx + 1, ~mod))
                    return true;
            }
        }
        if (!cur->next[c - 'a'])
            return false;
        return find (cur->next[c - 'a'], word, idx + 1, mod);
    }
    
    
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new struct Node();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto e : dict)
            insert(e);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return find (root, word, 0, false);
    }
};

class MagicDictionary {
private:
    set<string> st;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        st.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto e : dict) {
            st.insert(e);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int N = word.length();
        for (int i = 0; i < N; i++) {
            char c = word[i];
            for (int j = 0; j < 26; j++) {
                if  (c != ('a' + j)) {
                    word[i] = ('a' + j);
                    if (st.find(word) != st.end())
                        return true;
                }
            }
            word[i] = c;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
