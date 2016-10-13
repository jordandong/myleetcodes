/*
Given an integer matrix, find the length of the longest increasing path.
From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:
nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:
nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Tags Depth-first Search Topological Sort Memoization
*/

//T:O(M*N) S:O(M*N)
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int M = matrix.size();
        if (M == 0)
            return 0;
        int N = matrix[0].size();
        if (N == 0)
            return 0;
        
        // dp[i][j] means len of longest increasing continuous subsequence starting with A[i][j]
        vector<vector<int> > dp(M, vector<int>(N, 0));
        int res = 0;
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (dp[i][j] == 0)
                    res = max(res, LIP_Helper(matrix, i, j, INT_MIN, dp));
            }
        }
        
        return res;
    }
    
    int LIP_Helper(vector<vector<int>> &A, int i, int j, int last_val, vector<vector<int>> &dp) {
        if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size() || A[i][j] <= last_val)
            return 0;
        
        if (dp[i][j] > 0)
            return dp[i][j];
        
        dp[i][j] = max(dp[i][j], 1 + LIP_Helper(A, i + 1, j, A[i][j], dp));
        dp[i][j] = max(dp[i][j], 1 + LIP_Helper(A, i - 1, j, A[i][j], dp));
        dp[i][j] = max(dp[i][j], 1 + LIP_Helper(A, i, j + 1, A[i][j], dp));
        dp[i][j] = max(dp[i][j], 1 + LIP_Helper(A, i, j - 1, A[i][j], dp));
        return dp[i][j];
    }
};
