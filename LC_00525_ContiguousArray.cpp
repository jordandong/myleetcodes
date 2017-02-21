/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2

Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000.
Hide Tags Hash Table
Hide Similar Problems (M) Maximum Size Subarray Sum Equals k
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0, res = 0;
        mp[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] ? 1 : -1;
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            } else {
                res = max(res, i - mp[sum]);
            }
        }
        return res;
    }
};

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int N = nums.size();
        int sum = N, res = 0;
        vector<int> sums(2*N + 1, -1);
        sums[sum] = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] ? 1 : -1;
            if (sums[sum] == -1) {
                sums[sum] = i + 1;
            } else {
                res = max(res, i - sums[sum] + 1);
            }
        }
        return res;
    }
};
