/*
Given two integers n and k, find how many different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs.
We define an inverse pair as following:
For ith and jth element in the array, if i < j and a[i] > a[j] then it's an inverse pair; Otherwise, it's not.
Since the answer may very large, the answer should be modulo 10^9 + 7.

Example 1:
Input: n = 3, k = 0
Output: 1
Explanation: 
Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pair.

Example 2:
Input: n = 3, k = 1
Output: 2
Explanation: 
The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.

Note:
1. The integer n is in the range [1, 1000] and k is in the range [0, 1000].
*/

class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<long>> dp(n, vector<long>(k + 1, 0));
        dp[0][0] = 1;
        //dp[n][k] = sum{x = 0...n} dp[n - 1][k - x]
        for (int i = 1; i < n; i++) {
            for(int j = 0; j <= k; j++) {
                for(int x = 0; (j - x) >= 0 && x <= i; x++)
                    dp[i][j] += dp[i - 1][j - x];
                dp[i][j] = dp[i][j] % 1000000007;
            }
        }
        return (int)dp[n - 1][k];
    }
};

class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<long>  dp(k + 1, 0);
        dp[0] = 1;
        for (int i = 2; i <= n; i++) {
            //dp[n][k] = sum{x = 0...n} dp[n - 1][k - x]
            for (int j = 1; j <= k; j++) {
                dp[j] += dp[j - 1]; //dp[n][k] = sum{x = 0...k} dp[n - 1][x]
                dp[j] = dp[j] % 1000000007;
            }
            for(int j = k; j >= i; j--) { // if k > n, sum{x = 0 ... k-n} dp[n - 1][x] won't count
                dp[j] = dp[j] - dp[j - i] + 1000000007;
                dp[j] = dp[j] % 1000000007;
            }
        }
        return dp[k];
    }
};
