/*
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.
*/

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        long long res = 0;
        reversePairsHelper(nums, 0, nums.size() - 1, res);
        return res;
    }
    
    vector<int> reversePairsHelper(vector<int>& A, int s, int e, long long &res) {
        if (s > e)
            return {};
        if (s == e)
            return {A[s]};
        int m = s + (e - s)/2;
        vector<int> l = reversePairsHelper(A, s, m, res);
        vector<int> r = reversePairsHelper(A, m + 1, e, res);
        int i = 0, j = 0;
        vector<int> rtn;
        while (i < l.size() && j < r.size()) { //count
            if (l[i] > (2L * r[j])) {
                res += (r.size() - j);
                i++;
            } else {
                j++;
            }
        }

        i = 0, j = 0;
        while (i < l.size() && j < r.size()) {
            if (l[i] > r[j]) {
                rtn.push_back(l[i++]);
            } else {
                rtn.push_back(r[j++]);
            }
        }
        while (i < l.size())
            rtn.push_back(l[i++]);
        while (j < r.size())
            rtn.push_back(r[j++]);
        return rtn;
    }
};
