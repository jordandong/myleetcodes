/*
You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.

Example 1:
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5
Example 2:
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5
Example 3:
Input: [1,2,3,4,4,5]
Output: False
Note:
The length of the input is in range of [1, 10000]
*/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        vector<pair<int, int>> tbl;
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1, idx = -1;
            for (int j = 0; j < tbl.size(); j++) {
                if (nums[i] == tbl[j].first + 1 && tbl[j].second < l) {
                    l = tbl[j].second;
                    idx = j;
                }
            }
            if (idx == -1) {
                tbl.push_back({nums[i], 1});
            } else {
                tbl[idx].first = nums[i];
                tbl[idx].second++;
            }
        }
        
        for (int j = 0; j < tbl.size(); j++) {
            if (tbl[j].second < 3)
                return false;
        }
        return true;
    }
};
