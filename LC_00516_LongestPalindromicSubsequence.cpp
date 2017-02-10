/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:
"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".

Example 2:
Input:
"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".

Hide Tags Dynamic Programming
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int N = s.length();
        vector<vector<int>> dp(N, vector<int>(N, 1));
        for (int j = 1; j < N; j++) {
            for (int i = j - 1; i >= 0; i--) {
                if (s[j] == s[i]) {
                    dp[i][j] = 2 + ((i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0);
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][N - 1];
    }
};
