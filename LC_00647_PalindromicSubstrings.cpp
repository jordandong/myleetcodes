/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Note:
The input string length won't exceed 1000.
*/

class Solution {
public:
    int countSubstrings(string s) {
        int N = s.length();
        int res = N;
        for (int i = 0; i < N; i++) {
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < N && s[l--] == s[r++])
                res++;
        }
        
        for (int i = 0, j = 1; j < N; i++, j++) {
            if (s[i] != s[j])
                continue;
            res += 1;
            int l = i - 1, r = j + 1;
            while (l >= 0 && r < N && s[l--] == s[r++])
                res++;
        }
     
        return res;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int N = s.length(), res = 0;
        vector<vector<bool>> dp(N, vector<bool>(N, false));
        for (int j = 0; j < N; j++) {
            for (int i = j; i >= 0 ; i--) {
                if (i == j || ((i + 1) == j && s[i] == s[j])) {
                    dp[i][j] = true;
                } else{
                    dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                }
                res += dp[i][j];
            }
        }
        return res;            
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int res = s.length();
        for (int l = 2; l <= s.length(); l++) {
            for (int i = 0; i <= s.length() - l; i++) {
                if (check(s.substr(i, l)))
                    res++;
            }    
        }
        return res;
    }
    
    bool check(string a) {
        int i = 0, j = a.length() - 1;
        while (i <= j) {
            if (a[i++] != a[j--])
                return false;
        }
        return true;
    }
};
