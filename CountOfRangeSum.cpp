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

//T : O(N*logN) S : O(N)
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> sum;
        int N = nums.size();
        int ans = 0;
        sum.push_back(0);
        for (auto &e : nums)
            sum.push_back(sum.back() + e);
        countRangeSumMergeSort(sum, 0, sum.size() - 1, lower, upper, ans);
        return ans;
    }
    
    vector<long long> countRangeSumMergeSort(vector<long long> &sum, int s, int e, int lower, int upper, int &ans) {
        if (s == e)
            return {sum[s]};
        int mid = s + (e - s)/2;
        vector<long long> l = countRangeSumMergeSort(sum, s, mid, lower, upper, ans);
        vector<long long> r = countRangeSumMergeSort(sum, mid + 1, e, lower, upper, ans);
        vector<long long> res;
        int i = 0, j = 0;
        int lo = 0, hi = 0;
        
        while (i < l.size()) {
            while (lo < r.size() && r[lo] - l[i] < lower)
                lo++;
            while (hi < r.size() && r[hi] - l[i] <= upper)
                hi++;
            while (j < r.size() && r[j] < l[i])
                res.push_back(r[j++]);
            res.push_back(l[i++]);
            ans += hi - lo;
        }
        while (j < r.size())
            res.push_back(r[j++]);
        return res;
    }
};

//T : O(N ^ 2), S : O(N)
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> sum;
        int N = nums.size();
        int res = 0;
        sum.push_back(0);
        for (auto &e : nums)
            sum.push_back(sum.back() + e);
            
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j <= N; j++) {
                long long sub_sum = sum[j] - sum[i];
                if (lower <= sub_sum && sub_sum <= upper)
                    res++;
            }
        }
        return res;
    }
};
