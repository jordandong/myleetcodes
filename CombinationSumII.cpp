//============================================================================
// Given a collection of candidate numbers (C) and a target number (T),
// find all unique combinations in C where the candidate numbers sums to T.
//
// Each number in C may only be used once in the combination.
//
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … ,ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 10,1,2,7,6,1,5 and target 8,
// A solution set is:
// [1, 7]
// [1, 2, 5]
// [2, 6]
// 1, 1, 6]
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        int sum = 0;
        for (vector<int>::iterator it = candidates.begin(); it != candidates.end(); it++)
        	sum += *it;
        sort(candidates.begin(), candidates.end());
        if (candidates[0] > target || sum < target)
        	return result;
        	
        vector<int> combination;
        combinationSumHelper(candidates, target, 0, combination, result);
        return result;
    };

    void combinationSumHelper(vector<int> &candidates, int target, size_t i, vector<int> combination, vector<vector<int> > &result) {
        if (target <= 0) {
            if (target == 0)
                if (find(result.begin(), result.end(), combination) == result.end())
                    result.push_back(combination);
            return;
        }
        if (i == candidates.size())
        	return;
        combinationSumHelper(candidates, target, i + 1, combination, result);
        if (target - candidates[i] >= 0) {
            combination.push_back(candidates[i]);
            combinationSumHelper(candidates, target - candidates[i], i + 1, combination, result);
        }
    };
};

int main() {
    return 0;
}


class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> subset;
        vector<vector<int> > res;
        sort(num.begin(),num.end());
        comsum(num,0,target, subset, res);
        return res;
    }
    
    
    bool comsum(vector<int> &data, int index, int tg, vector<int> &subset, vector<vector<int> > &res){
        if(tg==0)
            return true;
        if(tg<0||index>=data.size())
            return false;
        
        for(int i=index;i<data.size();i++){
            if(i>index&&data.at(i)==data.at(i-1))
                continue;
            subset.push_back(data.at(i));      
            if(comsum(data, i+1, tg-data.at(i), subset, res)){
                res.push_back(subset);
                subset.pop_back();
            }
            else{
                subset.pop_back();
            }
        }
        return false;
    }
};
