/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 

Hide Tags Array Backtracking
*/

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> sol;
        vector<vector<int> > res;
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(candidates, 0, target, sol, res);
        return res;
    }
    
    void combinationSumHelper(vector<int> &data, int start, int tg, vector<int> &sol, vector<vector<int> > &res){
        if(tg == 0){
            res.push_back(sol);
            return;
        }
        if(tg < 0 || start >= data.size())
            return;
        
        for(int i = start; i < data.size(); i++){
            sol.push_back(data[i]);        
            combinationSumHelper(data, i, tg - data[i], sol, res);
            sol.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        if(candidates[0] > target)
        	return result;
        combinationSumHelper(candidates, target, 0, combination, result);
        return result;
    };

    void combinationSumHelper(vector<int> &candidates, int target, int i, vector<int> &combination, vector<vector<int> > &result) {
        if (target <= 0 || i == candidates.size()) {
            if (target == 0)
                result.push_back(combination);
            return;
        }

        combinationSumHelper(candidates, target, i + 1, combination, result);
        int j = 0;
        for(j = 1; j * candidates[i] <= target; j++) {
            combination.push_back(candidates[i]);
            combinationSumHelper(candidates, target - j * candidates[i], i + 1, combination, result);
        }
        
        while(j-- > 1)
            combination.pop_back();
    };
};
