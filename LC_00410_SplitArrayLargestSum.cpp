/*
Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
Write an algorithm to minimize the largest sum among these m subarrays.

Note:
Given m satisfies the following constraint: 1 ≤ m ≤ length(nums) ≤ 14,000.

Examples:

Input:
nums = [1,2,3,4,5]
m = 2
Output:
9

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5],
where the largest sum among the two subarrays is only 9.

Hide Tags Binary Search
*/

// T : O(NlogM), M is SUM(nums), S : O(1)
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int lo = 0, hi = 0;
        for (const auto &num : nums) {
            lo = max(lo, num);
            hi += num;
        }

        while (lo <= hi) {
            const auto mid = lo + (hi - lo) / 2;
            if (canSplit(nums, m, mid)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

private:
    bool canSplit(vector<int>& nums, int m, int sum) {
        int cnt = 1, curr_sum = 0;
        for (const auto &num : nums) {
            curr_sum += num;
            if (curr_sum > sum) {
                curr_sum = num;
                ++cnt;
            }
        }
        return cnt <= m;
    }
};
