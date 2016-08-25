/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

Hide Tags Backtracking
*/

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int> > res;
        vector<int> sol;
        if(k > n)
            return res;
        combineHelper(1, n, k, sol, res);
        return res;
    }
    
    void combineHelper(int start, int end, int k, vector<int> &sol, vector<vector<int> > &res){
        if(k == 0){
            res.push_back(sol);
            return;
        }
        
        for(int i = start; i <= end; i++){
            sol.push_back(i);
            combineHelper(i + 1, end, k - 1, sol, res);
            sol.pop_back();
        }
    }
};
