/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.

Hide Tags Sort Binary Search Tree
*/

//T:O(NlogK) S:O(K)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int N = nums.size();
        if (N == 0 || k <= 0 | t < 0)
            return false;
        multiset<int> val;
        for (int i = 0; i < N; i++) {
            if (i == 0) {
                val.insert(nums[i]); //logk
            } else {
                if(diff(nums[i], *val.begin()) <= t || diff(*val.rbegin(), nums[i]) <= t)
                    return true;
                val.insert(nums[i]); //logk
            }
            if( i >= k )
                val.erase(nums[i - k]); //logk
        }
        return false;
    }
    
    long long diff (long long a, long long b) {
        return a > b ? a - b : b - a;
    }
};
