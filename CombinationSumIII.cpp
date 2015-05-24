/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
Ensure that numbers within the set are sorted in ascending order.

Example 1:
Input: k = 3, n = 7
Output:
[[1,2,4]]

Example 2:
Input: k = 3, n = 9
Output:
[[1,2,6], [1,3,5], [2,3,4]]

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Hide Tags Array Backtracking
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> >  res;
        vector<int> sol;
        combinationSum3Helper(k, n, 1, 9, sol, res);
        return res;
    }
    
    void combinationSum3Helper(int k, int n, int start, int end, vector<int> &sol, vector<vector<int>> &res) {
        if ( k == 0 || n == 0 || n > k*9) {
            if ( k == 0 && n == 0) 
                res.push_back(sol);
            return;
        }
        
        for (int i = start; i <= end && n - i >= 0; i++) {
            sol.push_back(i);
            combinationSum3Helper(k - 1, n - i, i + 1, end, sol, res);
            sol.pop_back();
        }
    }
};
