/*
Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.

Hide Tags Binary Search Hash Table Two Pointers Sort
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> mp;
        vector<int> res;
        for (auto &e : nums1)
            mp[e] = true;
        for (auto &e : nums2) {
            if (mp[e]) {
                res.push_back(e);
                mp[e] = false;
            }
        }
        return res;
    }
};
