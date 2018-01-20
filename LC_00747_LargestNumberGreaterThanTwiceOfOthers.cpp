/*
In a given integer array nums, there is always exactly one largest element.
Find whether the largest element in the array is at least twice as much as every other number in the array.
If it is, return the index of the largest element, otherwise return -1.

Example 1:
Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x, 6 is more than twice as big as x.
The index of value 6 is 1, so we return 1.

Example 2:
Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.

Note:
1. nums will have a length in the range [1, 50].
2. Every nums[i] will be an integer in the range [0, 99].
*/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx = INT_MIN, res = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mx) {
                mx = nums[i];
                res = i;
            }
        }
        
        for (auto num : nums) {
            if (mx == num)
                continue;
            if (mx < num * 2)
                return -1;
        }
        return res;
    }
};

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx1 = -1, mx2 = -1, res = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mx1) {
                mx2 = mx1;
                mx1 = nums[i];
                res = i;
            } else if (nums[i] > mx2) {
                mx2 = nums[i];
            }
        }
        return (mx1 >= 2 * mx2) ? res : -1;
    }
};

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (idx1 == -1 || nums[i] > nums[idx1]) {
                idx2 = idx1;
                idx1 = i;
            } else if (nums[i] > nums[idx2]) {
                idx2 = i;
            }
        }
        return (idx2 == -1 || nums[idx1] >= 2 * nums[idx2]) ? idx1 : -1;
    }
};
