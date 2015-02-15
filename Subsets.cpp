/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

Hide Tags Array Backtracking Bit Manipulation
*/

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &nums) {
    	int n = nums.size();
    	int mx = 1 << n;
    	vector<vector<int> > res;
        sort(nums.begin(), nums.end());
    	for(int i = 0; i < mx; i++){
    	    vector<int> sol;
    	    for(int shift = 0; shift < n; shift++){
    	        if((i>>shift) & 0x1){
    	            sol.push_back(nums[shift]);
    	        }
    	    }
    	    res.push_back(sol);
    	}
    	return res;
    }
};
