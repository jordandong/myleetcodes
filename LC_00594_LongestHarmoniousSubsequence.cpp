/*
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].

Note: The length of the input array will not exceed 20,000.

Hide Tags Hash Table
*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;
        for (auto e : nums) {
            mp[e]++;
            if (mp[e + 1])
                res = max(res, mp[e] + mp[e + 1]);
            if (mp[e - 1])
                res = max(res, mp[e] + mp[e - 1]);
        }
        return res;
    }
};

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[i] == nums[j]) {
                j++;
            } else if (nums[i] + 1 == nums[j]) {
                j++;
                res = max(res, j - i);
            } else {
                i++;
            }
        }
        return res;
    }
};
