/*
Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].
*/

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<pair<int, int>> expected[26];
        int ans = 0;
        //wait char words[i][0] at word i index 0 and next char index is at 1
        for (int i = 0; i < words.size(); i++)
            expected[words[i][0] - 'a'].push_back({i, 1});
        for (char c : S) {
            auto advance = expected[c - 'a'];
            expected[c - 'a'].clear();
            for (auto it : advance) {
                int i = it.first, j = it.second;
                if (j == words[i].length()) // all expected chars in this word are found
                    ans++;
                else
                    expected[words[i][j] - 'a'].push_back({i, j + 1}); // new expected char
            }
        }
        return ans;
    }
};
