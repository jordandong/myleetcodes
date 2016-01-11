/*
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Tags Divide and Conquer Binary Search Tree
Hide Similar Problems (H) Count of Smaller Numbers After Self
*/

//T : O(N ^ 2), S : O(N)
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<int> sum;
        int N = nums.size();
        int res = 0;
        sum.push_back(0);
        for (auto &e : nums)
            sum.push_back(sum.back() + e);
            
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j <= N; j++) {
                int sub_sum = sum[j] - sum[i];
                if (lower <= sub_sum && sub_sum <= upper)
                    res++;
            }
        }
        return res;
    }
};
