/*
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6

Example 2:
Input: [1,2,3,4]
Output: 24

Note:
1. The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
2. Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int N = nums.size();
        if (N < 3)
            return 0;
        sort(nums.begin(), nums.end());
        return max(nums[0]*nums[1], nums[N - 3]*nums[N - 2])*nums[N - 1];
        //return max(nums[0]*nums[1]*nums[N - 1], nums[N - 3]*nums[N - 2]*nums[N - 1]);
    }
};

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int N = nums.size();
        if (N < 3)
            return 0;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        for (auto e : nums) {
            if (e > max1) {
                max3 = max2;
                max2 = max1;
                max1 = e;
            } else if (e > max2) {
                max3 = max2;
                max2 = e;
            } else if (e > max3) {
                max3 = e;
            }
            
            if (e < min1) {
                min2 = min1;
                min1 = e;
            } else if (e < min2) {
                min2 = e;
            }
        }
        //return max(max3 * max2 * max1, min1 * min2 * max1);
        return max(max3 * max2, min1 * min2) * max1;

    }
};
