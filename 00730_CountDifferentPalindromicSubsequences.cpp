/*
Given a string S, find the number of different non-empty palindromic subsequences in S, and return that number modulo 10^9 + 7.

A subsequence of a string S is obtained by deleting 0 or more characters from S.

A sequence is palindromic if it is equal to the sequence reversed.

Two sequences A_1, A_2, ... and B_1, B_2, ... are different if there is some i for which A_i != B_i.

Example 1:
Input: 
S = 'bccb'
Output: 6
Explanation: 
The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it occurs twice.
Example 2:
Input: 
S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
Output: 104860361
Explanation: 
There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 10^9 + 7.
Note:

The length of S will be in the range [1, 1000].
Each character S[i] will be in the set {'a', 'b', 'c', 'd'}.
*/

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.length();
        vector<vector<int>> next(n, vector<int>(4, -1));
        vector<vector<int>> prev(n, vector<int>(4, -1));
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < 4; k++) {
                if (S[i] == ('a' + k))
                    prev[i][k] = i;
                else if (i > 0)
                    prev[i][k] = prev[i - 1][k];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 0; k < 4; k++) {
                if (S[i] == ('a' + k))
                    next[i][k] = i;
                else if (i < n - 1)
                    next[i][k] = next[i + 1][k];
            }
        }
        return countPalindromicSubsequencesHelper(0, n - 1, prev, next, dp) - 1;
    }

private:
    int countPalindromicSubsequencesHelper(int i, int j, vector<vector<int>> &prev, vector<vector<int>> &next, vector<vector<int>> &dp) {
        if (dp[i][j])
            return dp[i][j];
        int ans = 1; //empty str
        if (i <= j) {
            for (int k = 0; k < 4; k++) {
                int ii = next[i][k], jj = prev[j][k];
                if (i <= ii && ii <= j)
                    ans += 1; //S[ii]
                if (-1 < ii && ii < jj) //S[ii] + xxx + S[jj]
                    ans += countPalindromicSubsequencesHelper(ii + 1, jj - 1, prev, next, dp);
                    ans %= 1000000007;
            }
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
};

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.length();
        vector<vector<int>> next(n, vector<int>(4, -1));
        vector<vector<int>> prev(n, vector<int>(4, -1));
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < 4; k++) {
                if (S[i] == ('a' + k))
                    prev[i][k] = i;
                else if (i > 0)
                    prev[i][k] = prev[i - 1][k];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 0; k < 4; k++) {
                if (S[i] == ('a' + k))
                    next[i][k] = i;
                else if (i < n - 1)
                    next[i][k] = next[i + 1][k];
            }
        }
        return countPalindromicSubsequencesHelper(0, n - 1, prev, next, dp);
    }

private:
    int countPalindromicSubsequencesHelper(int i, int j, vector<vector<int>> &prev, vector<vector<int>> &next, vector<vector<int>> &dp) {
        if (i > j)
            return 0;
        if (dp[i][j])
            return dp[i][j];
        int ans = 0;
        for (int k = 0; k < 4; k++) {
            int ii = next[i][k], jj = prev[j][k];
            if (ii < 0) //no this char
                continue;
            if (ii < jj) //S[ii] + S[jj], no middle chars
                ans++;
            if (ii <= j) {
                ans++; //S[ii] only
                ans += countPalindromicSubsequencesHelper(ii + 1, jj - 1, prev, next, dp); //S[ii] + dp(ii + 1, jj - 1) + S[jj]
                ans %= 1000000007;
            }
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
};
