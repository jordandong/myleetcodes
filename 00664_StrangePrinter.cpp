/*
There is a strange printer with the following two special requirements:

The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any places, and will cover the original existing characters.
Given a string consists of lower English letters only, your job is to count the minimum number of turns the printer needed in order to print it.

Example 1:
Input: "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".
Example 2:
Input: "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
Hint: Length of the given string will not exceed 100.
*/

class Solution {
public:
    int strangePrinter(string s) {
        int N = s.length();
        if (N == 0)
            return 0;
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int j = 0; j < N; j++) {
            dp[j][j] = 1;
            for (int i = 0; i < j; i++) {
                dp[i][j] = j - i + 1;
                for (int k = i; k < j; k++) {
                    //if s[j] == s[k], k could be printed when printing j
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j - 1] + (s[j] != s[k]));
                }
            }
        }
        return dp[0][N - 1];
    }
};
