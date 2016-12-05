/*
Define S = [s,n] as the string S which consists of n connected strings s. For example, ["abc", 3] ="abcabcabc".
On the other hand, we define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1.
For example, “abc” can be obtained from “abdbec” based on our definition, but it can not be obtained from “acbbe”.

You are given two non-empty strings s1 and s2 (each at most 100 characters long) and two integers 0 ≤ n1 ≤ 106 and 1 ≤ n2 ≤ 106.
Now consider the strings S1 and S2, where S1=[s1,n1] and S2=[s2,n2].Find the maximum integer M such that [S2,M] can be obtained from S1.

Example:
Input:
s1="acb", n1=4
s2="ab", n2=2
Return:
2

Hide Tags Dynamic Programming
*/

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int l1 = s1.length(), l2 = s2.length();
        //at s1[x1 % l1] == s2[x2 % l2], record the current len x1 and x2
        vector<vector<pair<int,int>>> dp(l1, vector<pair<int, int>>(l2, {-1, -1}));
        int x1 = 0, x2 = 0;
        while (x1 < l1 * n1) {
            while (s1[x1 % l1] != s2[x2 % l2]) {
                if (++x1 >= l1 * n1)
                    break;
            }
            if (x1 >= l1 * n1)
                break;
            int idx1 = x1 % l1, idx2 = x2 % l2;
            if (dp[idx1][idx2].first == -1) {
                dp[idx1][idx2] = {x1, x2};
            } else { //found the previous idx1 and idx2
                auto x = dp[idx1][idx2];
                int round = (l1 * n1 - x.first) / (x1 - x.first);
                x1 = x.first + round * (x1 - x.first); // x1 - x.first is repeated 
                x2 = x.second + round * (x2 - x.second); //x2 - x.second is repeated
            }
            if (x1 < l1 * n1) {
                x1++;
                x2++;
            }
        }
        return x2 / (n2 * l2);
    }
};
