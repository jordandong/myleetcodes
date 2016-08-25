/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Hide Tags Array Hash Table
*/

//T:O(n) S:O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for (auto e : nums) {
            if (mp[e])
                return true;
            mp[e] = true;
        }
        return false;
    }
};

//T:O(NlogN) S:O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int N = nums.size();
        if(N == 0)
            return false;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N - 1; i++)
            if(nums[i] == nums[i + 1])
                return true;
        return false;
    }
};
