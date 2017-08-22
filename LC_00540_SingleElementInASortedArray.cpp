/*
Given a sorted array consisting of only integers where every element appears twice except for one element which appears once.
Find this single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10

Note: Your solution should run in O(log n) time and O(1) space.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        /*
        int ans = 0;
        for (auto &e : nums)
            ans ^= e;
        return ans;
        */
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            mid &= 0xFFFFFFFE;
            if (nums[mid] == nums[mid + 1])
                lo = mid + 2;
            else
                hi = mid;
        }
        return nums[hi];
    }
};
