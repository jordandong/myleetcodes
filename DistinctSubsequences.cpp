//============================================================================
// Distinct Subsequences
// Given a string S and a string T, count the number of distinct subsequences
// of T in S.
//
// A subsequence of a string is a new string which is formed from the original
// string by deleting some (can be none) of the characters without disturbing
// the relative positions of the remaining characters. (ie, "ACE" is a
// subsequence of "ABCDE" while "AEC" is not).
//
// Here is an example:
// S = "rabbbit", T = "rabbit"
//	because rabbbit = rabb b it, ra b bbit, rab b bit, there are three.
//
// Return 3.
//============================================================================

//optimize space use
class Solution {
public:
    int numDistinct(string S, string T) {  
    // Start typing your C/C++ solution below  
    // DO NOT write int main() function  
 
    if(S.size() < T.size())
        return 0;
    int dp[T.size()+1];      
    dp[0] = 1;  
    for(int i=1; i <= T.size(); i++)  
        dp[i] = 0;  
    for(int i=1; i<= S.size(); i ++)  
        for(int j =T.size(); j>=1; j--)  
            if(S[i-1] == T[j-1])  
                dp[j]+= dp[j-1];  
    return dp[T.size()];
    } 
};


class Solution {
public:
    int numDistinct(string S, string T) {
        int N = S.size();
        int M = T.size();
        int dp[M+1][N+1];
        dp[0][0] = 1;
        for (int i = 1; i <= M; i++)
			dp[i][0] = 0;
        for (int j = 1; j <= N; j++)
			dp[0][j] = 1;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (T[i-1] == S[j-1])
					dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                else
					dp[i][j] = dp[i][j-1];
            }
        }
        return dp[M][N];
    }
};


class Solution {
public:
    int numDistinct(string S, string T) {
        int N = S.size();
        int M = T.size();
        int dp[2][N+1];
        dp[0][0] = 1;
        for (int j = 1; j <= N; j++)
			dp[0][j] = 1;
        
        for (int i = 1; i <= M; i++) {
            dp[i%2][0] = 0;
            for (int j = 1; j <= N; j++) {
                if (T[i-1] == S[j-1])
					dp[i%2][j] = dp[(i-1)%2][j-1] + dp[i%2][j-1];
                else
					dp[i%2][j] = dp[i%2][j-1];
            }
        }
        return dp[M%2][N];
    }
};
