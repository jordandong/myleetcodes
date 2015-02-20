/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Hide Tags Dynamic Programming String
*/

//DP
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int M = s1.length();
        int N = s2.length();
        if(M != N)
            return false;
        
        vector<vector<vector<bool> > > dp(N, vector<vector<bool> >(N, vector<bool>(N + 1, false)));
        //dp[i][j][l] means in s1 start at i, in s2 start at j, length is l are scramlbe
        for(int i = N - 1; i >= 0; i--){
            for(int j = N-  1; j >= 0; j--){
                for(int l = 1; l <= N - max(i, j); l++){
                    if(s1.substr(i, l) == s2.substr(j, l)){//string equal
                        dp[i][j][l] = true;
                    }else{
                        for(int k = 1; k < l; k++){
                            if(dp[i][j][k] && dp[i + k][j + k][l - k] || dp[i][j + l - k][k] && dp[i + k][j][l - k]){
                                dp[i][j][l] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][N];
    }
};

//Broute Force
class Solution {
public:
    bool isScramble(string s1, string s2) {
        return isScrambleHelper(s1, 0, s1.size() - 1, s2, 0, s2.size() - 1);
    };
    
    bool isSameCharSet(string &s1, int l1, int h1, string &s2, int l2, int h2){
        if (h1 - l1 != h2 - l2)
            return false;
        int c[256] = {0};
        for(int i = l1; i <= h1; i++)
            c[s1[i]]++;
        for(int i = l2; i <= h2; i++)
            c[s2[i]]--;
        for(int i = 0; i < 256; i++)
            if(c[i] != 0)
                return false;
        return true;
    };

    bool isScrambleHelper(string &s1, int l1, int h1, string &s2, int l2, int h2) {
        if(!isSameCharSet(s1, l1, h1, s2, l2, h2))
            return false;
        if (l1 == h1)
            return true;
        for (int len = 1; len < h1 - l1 + 1; len++) {
            if((isScrambleHelper(s1, l1, l1 + len - 1, s2, l2, l2 + len - 1) &&
                isScrambleHelper(s1, l1 + len, h1, s2, l2 + len, h2)) ||
               (isScrambleHelper(s1, l1, l1 + len - 1, s2, h2 - len + 1, h2) &&
                isScrambleHelper(s1, l1 + len, h1, s2, l2, h2 - len)))
                    return true;
        }
        return false;
    };
};
