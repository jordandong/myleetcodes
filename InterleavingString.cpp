/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

Hide Tags Dynamic Programming String
*/

//DP, optimaized space most
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() > s2.length())
            return isInterleave(s2, s1, s3);
        int sz1 = s1.length();
        int sz2 = s2.length();
        if(sz1 + sz2 != s3.length())
            return false;

        bool dp[sz1 + 1];
        memset(dp, 0 , sizeof(bool)*(sz1 + 1));
        dp[0] = true;
        for(int j = 0; j < sz1; j++)
            if(s1[j] == s3[j])
                dp[j + 1] = dp[j];
        
        for(int i = 0; i < sz2; i++){
            dp[0] = dp[0] && (s2[i] == s3[i]);  
            for(int j = 0; j < sz1; j++){
                dp[j + 1] = (dp[j] && s3[i + j + 1] == s1[j]) || (dp[j + 1] && s3[i + j + 1] == s2[i]); 
            }
        }
        return dp[sz1];
    }
};

//DP
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int M = s1.size();
        int N = s2.size();
        if (M + N != s3.size())
            return false;
        
        bool dp[2][N + 1];
        dp[0][0] = true;
        int c = 0;
        
        for (int j = 1; j <= N; j++) {
            if (dp[c][j-1] && s2[j - 1] == s3[j - 1])
                dp[c][j] = true;
            else
                dp[c][j] = false;
        }

        for (int i = 1; i <= M; i++){
            if (dp[c][0] && s1[i - 1] == s3[i - 1])
                dp[c^1][0] = true;
            else
                dp[c^1][0] = false;
            
            for (int j = 1; j <= N; j++) {
                if ((dp[c][j] && s1[i - 1] == s3[i + j - 1]) || (dp[c^1][j - 1] && s2[j - 1] == s3[i + j - 1]))
                    dp[c^1][j] = true;
                else
                    dp[c^1][j] = false;
            }
            c ^= 1;
        }
        return dp[c][N];
    }
};

//Recursion, cannot pass TLE
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length())
            return false;
        return isInterleaveHelper(s1, s2, s3, 0, 0, 0);
    }

    bool isInterleaveHelper(string &s1, string &s2, string &s3, int i, int j, int k) {
        if(i == s1.length() && j == s2.length() && k == s3.length())
			return true;
        if (k == s3.length())
			return false;
        if (i == s1.length() && j == s2.length())
			return false;

        return ((s1[i] == s3[k] && isInterleaveHelper(s1, s2, s3, i + 1, j, k + 1)) ||
                (s2[j] == s3[k] && isInterleaveHelper(s1, s2, s3, i, j + 1, k + 1)));
    }
};
