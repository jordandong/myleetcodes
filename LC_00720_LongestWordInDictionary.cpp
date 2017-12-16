/*
Given a list of strings words representing an English Dictionary,
find the longest word in words that can be built one character at a time by other words in words.
If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.

Example 1:
Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

Example 2:
Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".

Note:
1. All the strings in the input will only contain lowercase letters.
2. The length of words will be in the range [1, 1000].
3. The length of words[i] will be in the range [1, 30].
*/

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        set<string> st;
        string res = "";
        for (auto w : words) {
            int len = w.length();
            if (len == 1 || st.find(w.substr(0, len - 1)) != st.end()) {
                if (len > res.length())
                    res = w;
                st.insert(w);
            }
        }
        return res;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        set<string> st;
        string res = "";
        st.insert(res);
        for (auto w : words) {
            int len = w.length();
            if (st.find(w.substr(0, len - 1)) != st.end()) {
                if (len > res.length())
                    res = w;
                st.insert(w);
            }
        }
        return res;
    }
};

class TrieNode {
private:
    bool end;
    vector<TrieNode*> next;
public:
    TrieNode() {
        next = vector<TrieNode*>(26, NULL);
        end = false;
    }
    
    void add(string w, int idx) {
        if (idx == w.length()) {
            end = true;
            return;
        }
        if (next[w[idx] - 'a'] == NULL)
            next[w[idx] - 'a'] = new TrieNode();
        next[w[idx] - 'a']->add(w, idx + 1);
    }
    
    void searchMax(string &res, string &sol) {
        if (res.length() < sol.length())
            res = sol;
        for (int i = 0; i < 26; i++) {
            if (next[i] && next[i]->end) {
                sol.push_back('a' + i);
                next[i]->searchMax(res, sol);
                sol.pop_back();
            }
        }
    }
};

class Solution {
private:
    TrieNode root;
public:
    string longestWord(vector<string>& words) {
        for (auto w : words)
            root.add(w, 0);
        string sol = "", res = "";
        root.searchMax(res, sol);
        return res;
    }
};
