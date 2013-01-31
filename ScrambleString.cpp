//============================================================================
// Scramble String
// Given a string s1, we may represent it as a binary tree by partitioning it
// to two non-empty substrings recursively.
//
// Below is one possible representation of s1 = "great":
//
//    great
//   /    \
//  gr    eat
// / \    /  \
//g   r  e   at
//           / \
//          a   t
//To scramble the string, we may choose any non-leaf node and swap its two
// children.
//
//For example, if we choose the node "gr" and swap its two children, it
// produces a scrambled string "rgeat".
//
//    rgeat
//   /    \
//  rg    eat
// / \    /  \
//r   g  e   at
//           / \
//          a   t
//We say that "rgeat" is a scrambled string of "great".
//
//Similarly, if we continue to swap the children of nodes "eat" and "at", it
// produces a scrambled string "rgtae".
//
//    rgtae
//   /    \
//  rg    tae
// / \    /  \
//r   g  ta  e
//       / \
//      t   a
//We say that "rgtae" is a scrambled string of "great".
//
//Given two strings s1 and s2 of the same length, determine if s2 is a
// scrambled string of s1.
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    bool isSameCharSet(string &s1, int l1, int u1, string &s2, int l2, int u2) {
        if (u1-l1 != u2-l2)
        		return false;
        int c[256] = {0};
        for (int i = l1; i < u1; i++)
        		c[s1[i]]++;
        for (int i = l2; i < u2; i++)
        		c[s2[i]]--;
        for (int i = 0; i < 256; i++)
            if (c[i] != 0)
            		return false;
        return true;
    };

    bool isScrambleHelper(string &s1, int l1, int u1, string &s2, int l2, int u2) {
        if(!isSameCharSet(s1, l1, u1, s2, l2, u2))
        		return false;
        if (l1+1 == u1)
        		return true;
        for (int i = 1; i < u1-l1; i++) {
            if ((isScrambleHelper(s1, l1, l1 + i, s2, l2, l2 + i) && isScrambleHelper(s1, l1 + i, u1, s2, l2 + i, u2))
                    || (isScrambleHelper(s1, l1, l1 + i, s2, u2 - i, u2) && isScrambleHelper(s1, l1 + i, u1, s2, l2, u2 - i)))
                return true;
        }
        return false;
    };

    bool isScramble(string s1, string s2) {
        return isScrambleHelper(s1, 0, s1.size(), s2, 0, s2.size());
    };
};

int main() {
    return 0;
}


class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //1. 如果两个substring相等的话，则为true
        //2. 如果两个substring中间某一个点，左边的substrings为scramble string，同时右边的substrings也为scramble string，则为true

        //3. 如果两个substring中间某一个点，s1左边的substring和s2右边的substring为scramble string, 同时s1右边substring和s2左边的substring也为scramble string，则为true
        
        int n=s1.length();
        bool ***dp=new bool**[n];
        for(int i1=0;i1<n;i1++){
            dp[i1] = new bool*[n];
            for(int i2=0;i2<n;i2++){
                dp[i1][i2]=new bool[n+1];
            }
        }
        
        for(int i1=0;i1<n;i1++)
            for(int i2=0;i2<n;i2++)
                for(int i3=0;i3<n+1;i3++)
                    dp[i1][i2][i3]=false;
        
        for(int i=n-1; i>=0; i--)
            for(int j=n-1; j>=0; j--)
                for(int k=1; k<=n-max(i,j);k++){
                    if(!s1.substr(i,k).compare(s2.substr(j,k)))
                        dp[i][j][k]=true;
                    else{
                        for(int l=1; l<k; l++){
                            if(dp[i][j][l] && dp[i+l][j+l][k-l] || dp[i][j+k-l][l] && dp[i+l][j][k-l]){
                                dp[i][j][k]=true;
                                break;
                            }
                        }
                    }
                }
        return dp[0][0][n];
    }
};
