/*
Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

Example 1:
Input:
nums = [1,3,1]
k = 1
Output: 0 
Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Note:
2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.
*/

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums[n - 1] - nums[0];
        while (lo < hi){
            int mid = lo + (hi - lo) / 2;
            int i = 0, j = 1, cnt = 0;
            while (j < n) { //two pointers
                if (nums[j] - nums[i] <= mid) {
                    cnt += (j - i);
                    j++;
                } else {
                    i++;
                }
            }
            if (cnt >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return hi;
    }
};
