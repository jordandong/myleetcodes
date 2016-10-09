/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Both the array size and each of the array element will not exceed 100.

Example 1:
Input: [1, 5, 11, 5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: [1, 2, 3, 5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

Hide Tags Dynamic Programming
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto &e : nums)
            sum += e;
        if (sum % 2 != 0)
            return false;
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (auto &e : nums) {
            for (int V = sum; V >= e; V--) {
                if (dp[V - e])
                    dp[V] = true;
                if (dp[sum])
                    return true;
            }
        }
        return dp[sum];
    }
};
