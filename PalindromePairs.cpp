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
                    string tmp = cur.substr(k);
                    reverse(tmp.begin(), tmp.end());
                    if(table.find(tmp) != table.end() && table[tmp] != i)
                        res.push_back({table[tmp], i});
                }
                if (isPal(cur, k, cur.size() - 1)) {
                    string tmp = cur.substr(0, k); 
                    reverse(tmp.begin(), tmp.end());
                    if (table.find(tmp) != table.end() && i != table[tmp] && cur.size() > words[table[tmp]].size())
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
