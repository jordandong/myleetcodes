/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

Hide Tags Array Hash Table
*/

//T : O(N), S : O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(target - nums[i]) != mp.end())
                return {mp[target - nums[i]], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};

//T: O(NlogN)  S:O(N) 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> data;
        for (int i = 0; i < nums.size(); i++)
            data.push_back({nums[i], i});
        sort(data.begin(), data.end());
        int lo = 0, hi = data.size() - 1;
        while (lo < hi) {
            int sum = data[lo].first + data[hi].first;
            if (sum == target)
                return {min(data[lo].second, data[hi].second), max(data[lo].second, data[hi].second)};
            if (sum < target)
                lo++;
            else
                hi--;
        }
        return {};
    }
};
