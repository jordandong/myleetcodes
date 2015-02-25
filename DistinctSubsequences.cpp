/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

Hide Tags Dynamic Programming String
*/

//optimize space use
class Solution {
public:
    int numDistinct(string S, string T) {  
        int M = S.size();
        int N = T.size();
        if(M < N)
            return 0;
        int dp[N + 1];
        memset(dp, 0, sizeof(int)*(N + 1));
        dp[0] = 1;

        for(int i = 1; i <= M; i ++){
            for(int j = N; j >= 1; j--){  
                if(S[i-1] == T[j-1])
                    dp[j] += dp[j-1];//use and not use
            }
        }
        return dp[N];
    }
};

class Solution {
public:
    int numDistinct(string S, string T) {
        int M = S.size();
        int N = T.size();
        int dp[2][N + 1];
        memset(dp, 0, sizeof(int)*2*(N + 1));
        int c = 0;
        dp[c][0] = 1;

        for(int i = 1; i <= M; i++) {
            dp[c^1][0] = dp[c][0];
            for(int j = 1; j <= N; j++) {
                if (S[i - 1] == T[j - 1])
					dp[c^1][j] = dp[c][j - 1] + dp[c][j];
                else
					dp[c^1][j] = dp[c][j];
            }
            c ^= 1;
        }
        return dp[c][N];
    }
};

class Solution {
public:
    int numDistinct(string S, string T) {
        int N = S.size();
        int M = T.size();
        int dp[2][N + 1];
        memset(dp, 0, sizeof(int)*2*(N + 1));
        int c = 0;
        for(int j = 0; j <= N; j++)
            dp[c][j] = 1;
        
        for(int i = 1; i <= M; i++) {
            dp[c^1][0] = 0;
            for(int j = 1; j <= N; j++) {
                if (T[i - 1] == S[j - 1])
                    dp[c^1][j] = dp[c][j - 1] + dp[c^1][j - 1];
                else
                    dp[c^1][j] = dp[c^1][j - 1];
            }
            c ^= 1;
        }
        return dp[c][N];
    }
};
