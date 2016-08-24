/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:
Given [3, 1, 5, 8]
Return 167
nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

Credits:
Special thanks to @peisi for adding this problem and creating all test cases.

Hide Tags Divide and Conquer Dynamic Programming
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int nums_all[nums.size() + 2];
        int n = 1;
        for (int x : nums) {
            if (x > 0) {
                //0 could be burst first without changing the results
                nums_all[n++] = x;
            }
        }
        nums_all[0] = 1;
        nums_all[n++] = 1;
        
        int dp[n][n] = {};
        //dp from ending to begining
        for (int k = 2; k < n; ++k) { //burst (k-1)th ballon from the ending
            for (int left = 0; left < n - k; ++left) {
                int right = left + k;
                for (int i = left + 1; i < right; ++i) {
                    //burst balloon at i will not affect the results on the left or right side on next step 
                    dp[left][right] = max(dp[left][right],
                         nums_all[left] * nums_all[i] * nums_all[right] + dp[left][i] + dp[i][right]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size() , 0));
        for (int len = 1; len <= n; ++len) {
            for (int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k) {
                    dp[left][right] = max(dp[left][right], nums[left - 1] * nums[k] * nums[right + 1] + dp[left][k - 1] + dp[k + 1][right]);
                }
            }
        }
        return dp[1][n];
    }
};
