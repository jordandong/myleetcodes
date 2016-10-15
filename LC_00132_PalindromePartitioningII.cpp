/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

Hide Tags Dynamic Programming
*/

//optimize the index to understand better
class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        if(len < 2)
            return 0;
        int dp[len + 1]; // min cut of at length i
        for(int i = 1; i <= len; i++)
            dp[i] = len;
        dp[0] = -1;
        
        bool dp1[len][len]; // from index i to j is palindrome
        for(int i = 0; i < len; i++)
            for(int j = 0; j < len; j++)
                    dp1[i][j] = (i >= j);
        
        for(int i = 0; i < len; i++){
            for(int j = i; j >= 0; j--){
                if(s[j] == s[i] && (i == 0 || j == len - 1 || dp1[j + 1][i - 1])){
                    dp[i + 1] = min(dp[i + 1], dp[j] + 1);
                    dp1[j][i] = true;
                }
            }
        }
        return dp[len];
    }
};
