/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

Hide Tags Dynamic Programming String
*/

class Solution {
public:
    int numDecodings(string s) {
        int N = s.length();
        if(N == 0 || s[0] == '0')
            return 0;
            
        int dp[N+1];
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 1; i < N; i++){
            if(s[i] != '0')//using single digit
                dp[i + 1] = dp[i];
            else
                dp[i + 1] = 0;
        
            if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))//using two digits
                dp[i + 1] += dp[i - 1];
        }
        return dp[N];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        int res = 1, a = 1, b = 1;
        if (s.length() == 0 || s[0] == '0')
            return 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != '0') {
                res = b;
            } else {
                res = 0;
            }
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))
                res += a;
            a = b;
            b = res;
        }
        return res;
    }
};
