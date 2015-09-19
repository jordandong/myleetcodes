/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Hide Tags Array Two Pointers
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0, walk = 0, N = nums.size();
        while (walk < N) {
            if (nums[walk] != 0) 
                swap(nums[zero++], nums[walk++]);
            else
                walk++;
        }
    }
};
