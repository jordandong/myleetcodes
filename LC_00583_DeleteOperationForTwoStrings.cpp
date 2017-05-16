/*
Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Note:
1. The length of given words won't exceed 500.
2. Characters in given words can only be lower-case letters.

Hide Tags String
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        int dp[len1 + 1][len2 + 1];
        for (int x = 0; x < len1 + 1; x++) {
            for (int y = 0; y < len2 + 1; y++) {
                if (x == 0 || y == 0) {
                    dp[x][y] = x + y;
                } else if (word1[x - 1] == word2[y - 1]) {
                    dp[x][y] = dp[x - 1][y - 1];
                } else {
                    dp[x][y] = min(dp[x - 1][y], dp[x][y - 1]) + 1;
                }
            }
        }
        return dp[len1][len2];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        return word1.length() + word2.length() - 2 * longestCommonSubsequence(word1, word2);
    }

private:
    int longestCommonSubsequence(string &A, string &B) {
        int sza = A.length();
        int szb = B.length();
        if(sza == 0 || szb == 0)
            return 0;

        int dp[2][sza + 1];
        int c = 0;
        memset(dp, 0, sizeof(int)*2*(sza+1));
        
        for (int i = 0; i < szb; i++){
            for (int j = 0; j < sza; j++){
                if (B[i] == A[j]){
                    dp[c][j + 1] = dp[c ^ 1][j] + 1;
                } else {
                    dp[c][j + 1] = max(dp[c][j], dp[c ^ 1][j + 1]);
                }
            }
            c ^= 1;
        }
        return dp[c ^ 1][sza];
    }
};
