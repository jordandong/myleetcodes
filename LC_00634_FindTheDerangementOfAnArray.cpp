/*
In combinatorial mathematics, a derangement is a permutation of the elements of a set, such that no element appears in its original position.

There's originally an array consisting of n integers from 1 to n in ascending order, you need to find the number of derangement it can generate.

Also, since the answer may be very large, you should return the output mod 10^9 + 7.

Example 1:
Input: 3
Output: 2
Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].

Note:
n is in the range of [1, 106].
*/

class Solution {
public:
    int findDerangement(int n) {
        if (n <= 1)
            return 0;
        int MOD = 1000000007;
        //dp(n) = (dp(n - 1) + dp(n - 2))*(n - 1);
        //https://en.wikipedia.org/wiki/Derangement
        long dp1 = 0, dp2 = 1, dp3 = 1;
        for (int i = 3; i <= n; i++) {
            dp3 = ((i - 1) * (dp1 + dp2)) % MOD;
            dp1 = dp2;
            dp2 = dp3;
        }
        return dp3;
    }
};
