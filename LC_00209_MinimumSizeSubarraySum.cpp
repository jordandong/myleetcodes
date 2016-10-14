/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Hide Tags Array Two Pointers Binary Search
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int N = nums.size();
        if(N == 0)
            return 0;
        vector<int> sums(N + 1, 0);
        for(int i = 0; i < N; i++)
            sums[i + 1] = sums[i] + nums[i];
        
        int lo = 0, hi = 1;
        int res = N + 1;
        while (hi <= N) {
            while(lo < hi && sums[hi] - sums[lo] >= s){
                res = min(res, hi - lo);
                lo++;
            }
            hi++;
        }
        return res <= N ? res : 0;
    }
};
