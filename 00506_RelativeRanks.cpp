/*
Given scores of N athletes, find their relative ranks and the men with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> rank;
        for(int i = 0; i < nums.size(); ++i)
            rank.push_back(i);
        sort(rank.begin(), rank.end(),
            [&](int a, int b) { return nums[a] > nums[b];});
        
        vector<string> ans(nums.size());
        for(int i = 3; i < nums.size(); ++i)
            ans[rank[i]] = to_string(i + 1);
        
        if (nums.size() > 0)
            ans[rank[0]] = "Gold Medal";
        if (nums.size() > 1)
            ans[rank[1]] = "Silver Medal";
        if (nums.size() > 2)
            ans[rank[2]] = "Bronze Medal";
        return ans;
    }
};
