/*
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

Note:
1. The length of the given array won't exceed 1000.
2. The integers in the given array are in the range of [0, 1000].

Hide Tags Array
*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int N = nums.size();
        if (N == 0)
            return 0;
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int k = N - 1; k >= 0; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] <= nums[k]) {
                    i++;
                } else {
                    res += j - i;
                    j--;
                }
            }
        }
        return res;
    }
};
