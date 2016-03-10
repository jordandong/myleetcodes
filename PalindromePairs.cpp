/*
Given a list of unique words. Find all pairs of indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]

Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

//T : O(N*k^2) S : O(N)
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> table;

        for(int i = 0; i < words.size(); i++)
            table[words[i]] = i;

        for (int i = 0; i < words.size(); i++) {
            string cur = words[i];
            for (int k = 0; k <= cur.size(); k++) {
                if (isPal(cur, 0, k - 1)) {
                    string tmp = cur.substr(k); //the right side
                    reverse(tmp.begin(), tmp.end());
                    //found match which could be attached to left
                    if(table.find(tmp) != table.end() && table[tmp] != i)
                        res.push_back({table[tmp], i});
                }
                //k < cur.size() condition is to avoid duplication when the cur string itself is not Pal, which is used in above codes
                if (k < cur.size() && isPal(cur, k, cur.size() - 1)) {
                    string tmp = cur.substr(0, k);  //the left side
                    reverse(tmp.begin(), tmp.end());
                    //found match which could be atached to right
                    if (table.find(tmp) != table.end() && i != table[tmp])
                        res.push_back({i, table[tmp]});
                }
            }
        }
        return res;
    }

private:
    bool isPal(string &s, int start, int end) {
        while (start < end && s[start] == s[end]) {
            start++;
            end--;
        };
        return start >= end;
    }
};


//Memory Limit Exceeded
// Time:  O(n * k), n is the number of the words, k is the max length of the words.
// Space: O(n * k)
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        TrieNode trie;
        for (int i = 0; i < words.size(); ++i) {
            trie.insert(words[i], i);
        }
        for (int i = 0; i < words.size(); ++i) {
            trie.find(words[i], i, &res);
        }
        return res;
    }

private:
    struct TrieNode {
        int word_idx = -1;
        unordered_map<char, TrieNode *> leaves;
        
        void insert(const string& s, int i) {
            auto* p = this;
            for (const auto& c : s) {
                if (p->leaves.find(c) == p->leaves.cend()) {
                    p->leaves[c] = new TrieNode;
                }
                p = p->leaves[c];
            }
            p->word_idx = i;
        }

        void find(const string& s, int idx, vector<vector<int>> *res) {
            auto* p = this;
            for (int i = s.length() - 1; i >= 0; --i) {
                if (p->leaves.find(s[i]) != p->leaves.cend()) {
                    p = p->leaves[s[i]];
                    if (p->word_idx != -1 && p->word_idx != idx &&
                        is_palindrome(s, i - 1)) {
                        res->push_back({p->word_idx, idx});
                    }
                } else {
                    break;
                }
            }
        }

        bool is_palindrome(const string& s, int j) {
            int i = 0;
            while (i <= j) {
                if (s[i++] != s[j--]) {
                    return false;
                }
            }
            return true;
        }

        ~TrieNode() {
            for (auto& kv : leaves) {
                if (kv.second) {
                    delete kv.second;
                }
            }
        }
    };
};
