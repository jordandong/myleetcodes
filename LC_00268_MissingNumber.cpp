/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Hide Tags Array Math Bit Manipulation
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int i = 0;
        while (i < N) {
            if (nums[i] != i && nums[i] < N) {
                swap(nums[i], nums[nums[i]]);
            } else {
                i++;
            }
        }
        for (int i = 0; i < N; i++) {
            if (nums[i] != i)
                return i;
        }
        return N;
    }
};
