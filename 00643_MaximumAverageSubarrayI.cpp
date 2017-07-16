/*
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int N = nums.size();
        if (k > N)
            return 0;
        double sum = 0, res = INT_MIN;
        for (int i = 0; i < N; i++) {
            sum += nums[i];
            if (i >= k)
                sum -= nums[i - k];
            if (i >= k - 1)
                res = res > sum / k ? res : (sum / k);
        }
        return res;
    }
};
