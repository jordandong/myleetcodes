/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Note:
1. Then length of the input array is in range [1, 10,000].
2. The input array may contain duplicates, so ascending order here means <=.

Hide Tags Array
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int N = nums.size();
        if (N == 0)
            return 0;
        int u_start = -1, u_end = -2;
        int mx = nums[0], mi = nums[N - 1];
        for (int i = 0; i < N; i++) {
            if (nums[i] < mx) {
                u_end = i;
            } else {
                mx = nums[i];
            }
        }
        for (int i = N - 1; i >= 0; i--) {
            if (nums[i] > mi) {
                u_start = i;
            } else {
                mi = nums[i];
            }
        }
        return u_end - u_start + 1;
    }
};
