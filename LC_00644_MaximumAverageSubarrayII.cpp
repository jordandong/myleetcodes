/*
Given an array consisting of n integers, find the contiguous subarray whose length is greater than or equal to k that has the maximum average value.
And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation:
when length is 5, maximum average value is 10.8,
when length is 6, maximum average value is 9.16667.
Thus return 12.75.

Note:
1. 1 <= k <= n <= 10,000.
2. Elements of the given array will be in range [-10,000, 10,000].
3. The answer with the calculation error less than 10-5 will be accepted.
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double l = INT_MAX, r = INT_MIN;
        int N = nums.size();
        for (int i = 0; i < N; ++i) {
            if (nums[i] < l)
                l = nums[i]; //min possible result
            if (nums[i] > r)
                r = nums[i]; //max possible result
        }

        vector<double> sum(N + 1, 0);
        while (r - l >= 1e-6) {
            double mid = (l + r) / 2.0; // binary search
            double min_pre = 0;
            bool check = false;
            for (int i = 1; i <= N; ++i) {
                sum[i] = sum[i - 1] + nums[i - 1] - mid;
                if (i >= k && sum[i] - min_pre >= 0) {
                    check = true;
                    break;
                }
                if (i >= k)
                    min_pre = min(min_pre, sum[i - k + 1]);
            }
            if (check)
                l = mid;
            else
                r = mid;
        }
        return l;
        
    }
};
