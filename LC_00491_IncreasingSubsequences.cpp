/*
Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

Note:
1. The length of the given array will not exceed 15.
2. The range of integer in the given array is [-100,100].
3. The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.

Hide Tags Depth-first Search
*/

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        if (nums.size() < 2)
            return {};
        findSubsequencesHelper(nums, 0, ans, res);
        return res;
    }
    
    void findSubsequencesHelper(vector<int>& nums, int idx, vector<int>& ans, vector<vector<int>>& res) {
        if (idx == nums.size())
            return;
        
        set<int> st;
        for (int i = idx; i < nums.size(); i++) {
            if (st.find(nums[i]) != st.end())
                continue;
            if (ans.size() == 0 || nums[i] >= ans.back()) {
                ans.push_back(nums[i]);
                if (ans.size() >= 2)
                    res.push_back(ans);
                findSubsequencesHelper(nums, i + 1, ans, res);
                ans.pop_back();
            }
            st.insert(nums[i]);
        }
    }
};
