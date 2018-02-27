/*
We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape. These shapes may be rotated.
XX  <- domino

XX  <- "L" tromino
X

Given N, how many ways are there to tile a 2 x N board? Return your answer modulo 10^9 + 7.
(In a tiling, every square must be covered by a tile.
Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.)

Example:
Input: 3
Output: 5
Explanation: 
The five different ways are listed below, different letters indicates different tiles:
XYZ XXZ XYY XXY XYY
XYZ YYZ XZZ XYY XXY

Note:
N will be in range [1, 1000].
*/

class Solution {
public:
    int numTilings(int N) {
        //dp[n] = dp[n-1] + dp[n-2] + 2*(dp[n-3] + … + d[0])
        //      = dp[n-1] + dp[n-2] + dp[n-3] + dp[n-3] + 2*(dp[n-4] + … + d[0])
        //      = dp[n-1] + dp[n-3] + (dp[n-2] + dp[n-3] + 2*(dp[n-4] + … + d[0]))
        //      = dp[n-1] + dp[n-3] + dp[n-1]
        //      = 2 * dp[n-1] + dp[n-3]
        //..o x  ..o xx  ..o xxy/xyy ..o xyyz/xxzz ..o xaazz/xxyyz ..o xbbccz/xxaazz
        //..o x  ..o yy  ..o xyy/xxy ..o xxzz/xyyz ..o xxyyz/xaazz ..o xxaazz/xbbccz
        long long n_1 = 5, n_2 = 2, n_3 = 1, mod = 1000000007;
        if (N == 1)
            return n_3;
        if (N == 2)
            return n_2;
        
        for (int i = 4; i <= N; i++) {
            int n = (2 * n_1 + n_3) % mod;
            n_3 = n_2;
            n_2 = n_1;
            n_1 = n;
        }
        return n_1 % mod;
    }
};
