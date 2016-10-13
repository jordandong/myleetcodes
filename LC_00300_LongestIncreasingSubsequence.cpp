/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.
Subscribe to see which companies asked this question
Hide Tags Dynamic Programming Binary Search
*/

//replace candidates, T : O(NlogN), S : O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        if(N == 0 || N == 1)
            return N;

        vector<int> lis;
        lis.push_back(nums[0]);
        
        for (int i = 1; i < N; i++) {
            if (nums[i] > lis.back()) {
                lis.push_back(nums[i]);
            } else {
                int hi = lis.size() - 1;
                int lo = 0;
                while (lo < hi) {
                    int mid = lo + (hi - lo)/2;
                    if (lis[mid] < nums[i]) {
                        lo = mid + 1;
                    } else {
                        hi = mid;
                    }
                }
                lis[lo] = nums[i];
            }
        }
        return lis.size();
    }
};

//DP, T : O(N^2), S : O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        if (N == 0)
            return 0;
        vector<int> mp(N, 1);
        int mx = 1;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    mp[i] = max(mp[i], mp[j] + 1);
                    mx = max(mx, mp[i]);
                }
            }
        }
        return mx;
    }
};
