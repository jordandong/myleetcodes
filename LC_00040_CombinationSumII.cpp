/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 

Hide Tags Array Backtracking
*/

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<int> sol;
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        combinationSum2Helper(num, 0, target, sol, res);
        return res;
    }
    
    void combinationSum2Helper(vector<int> &data, int start, int tg, vector<int> &sol, vector<vector<int> > &res){
        if(tg <= 0 || start >= data.size()){
            if(tg == 0)
                res.push_back(sol);
            return;
        }
        
        for(int i = start; i < data.size(); i++){
            if(i > start && data[i] == data[i-1])
                continue;
            sol.push_back(data[i]);
            combinationSum2Helper(data, i + 1, tg - data[i], sol, res);
            sol.pop_back();
        }
    }
};
