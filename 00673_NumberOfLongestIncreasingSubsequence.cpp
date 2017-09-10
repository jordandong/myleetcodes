/*
Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int N = nums.size();
        if (N <= 0)
            return N;
        vector<pair<int, int>> dp(N, pair<int, int>{1, 1});
        pair<int, int> res = {1, 1};
        for (int j = 1; j < N; j++) {
            int l = 1;
            for (int i = j; i >= 0; i--) {
                if (i == j) {
                    dp[j].first = 1;
                    dp[j].second = 1;
                    continue;
                }
                if (nums[j] > nums[i]) {
                    l = dp[i].first + 1;
                    if (l > dp[j].first) {
                        dp[j].first = l;
                        dp[j].second = dp[i].second;
                    } else if (l == dp[j].first) {
                        dp[j].second += dp[i].second;
                    }                   
                }
            }
            if (dp[j].first > res.first) {
                res.first = dp[j].first;
                res.second = dp[j].second;
            } else if (dp[j].first == res.first) {
                res.second += dp[j].second;
            }
        }
        return res.second;
    }
};
