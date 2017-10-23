/*
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.
*/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto e : nums)
            sum += e;
        if (sum % k)
            return false;
        vector<int> kset(k, 0);
        return canPartitionKSubsetsHelper(nums, sum / k, 0, kset);
    }
private:
    bool canPartitionKSubsetsHelper(vector<int>& nums, int val, int pos, vector<int> &kset) {
        if (pos == nums.size())
            return true;
        for (int i = 0; i < kset.size(); i++) {
            if (kset[i] + nums[pos] > val)
                continue;
            kset[i] += nums[pos];
            if(canPartitionKSubsetsHelper(nums, val, pos + 1, kset))
                return true;
            kset[i] -= nums[pos];
            if (kset[i] == 0)
                break;
        }
        return false;
    }
    
};
