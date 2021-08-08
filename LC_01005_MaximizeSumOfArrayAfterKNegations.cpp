/*
Given an integer array nums and an integer k, modify the array in the following way:

choose an index i and replace nums[i] with -nums[i].
You should apply this process exactly k times. You may choose the same index i multiple times.

Return the largest possible sum of the array after modifying it in this way.

 

Example 1:

Input: nums = [4,2,3], k = 1
Output: 5
Explanation: Choose index 1 and nums becomes [4,-2,3].
Example 2:

Input: nums = [3,-1,0,2], k = 3
Output: 6
Explanation: Choose indices (1, 2, 2) and nums becomes [3,1,0,2].
Example 3:

Input: nums = [2,-3,-1,5,-4], k = 2
Output: 13
Explanation: Choose indices (1, 4) and nums becomes [2,3,-1,5,4].
 

Constraints:

1 <= nums.length <= 104
-100 <= nums[i] <= 100
1 <= k <= 104
*/

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        map<int, int> pos, neg;
        for (auto e : nums) {
            if (e >= 0) {
                pos[e]++;
            } else {
                neg[e]++;
            }
        }
        int ans = 0;
        for (auto e : neg) {
            while (e.second-- > 0) {
                if (k > 0) {
                    pos[-e.first]++;
                    k--;
                } else {
                    ans += e.first;
                }
            }
        }
            
        for (auto  e : pos) {
            while (e.second-- > 0) {
                if (k > 0 && (k % 2)) {
                    ans -= e.first;
                    k = 0;
                } else {
                    ans += e.first;
                }
            }
        }
        return ans;
    }
};

