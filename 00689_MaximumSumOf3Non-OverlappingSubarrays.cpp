/*
In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

Example:
Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
Note:
nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).

*/

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> l_pos(N - k + 1, 0), r_pos(N - k + 1, N - k), sums(N - k + 1, 0);
        vector<int> ans;
        for (int total = 0, i = 0; i < N; i++) {
            total += nums[i];
            if (i >= k - 1) {
                sums[i - k + 1] = total; //k sums start begin at index i - k + 1
                total -= nums[i - k + 1];
            }
        }
        
        //left mx start index position
        for (int i = 0, mx = 0; i <= N - k; i++) {
            if (sums[i] > mx) {
                mx = sums[i];
                l_pos[i] = i;
            } else {
                l_pos[i] = l_pos[i - 1];
            }
        }
        
        //right mx start index position
        for (int i = N - k, mx = 0; i >= 0; i--) {
            if (sums[i] >= mx) {
                mx = sums[i];
                r_pos[i] = i;
            } else {
                r_pos[i] = r_pos[i + 1];
            }
        }
        
        //test middle index k ~ N - k - k
        for (int i = k, mx = 0; i <= N - k - k; i++) {
            int l = l_pos[i - k], r = r_pos[i + k];
            int sum = sums[l] + sums[i] + sums[r];
            if (sum > mx) {
                mx = sum;
                ans = {l, i, r};
            }
        }
        
        return ans;
    }
};
