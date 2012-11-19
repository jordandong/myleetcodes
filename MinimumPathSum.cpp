//============================================================================
// Given a m x n grid filled with non-negative numbers, find a path from top
// left to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.
//============================================================================

#include <vector>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int M = grid.size();
        if (M == 0) return 0;
        int N = grid[0].size();
        if (N == 0) return 0;

        int dp[M][N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (i == 0 && j == 0) dp[i][j] = grid[i][j];
                else if (i == 0) dp[i][j] = dp[i][j-1] + grid[i][j];
                else if (j == 0) dp[i][j] = dp[i-1][j] + grid[i][j];
                else dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[M-1][N-1];
    }
};

int main() {
    return 0;
}


class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = grid.size();
        int n = grid[0].size();
        
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            if(i<=1)
                dp[i][0]=0;
            else
                dp[i][0]=INT_MAX;
        }
        for(int j=0;j<=n;j++){
            if(j<=1)
                dp[0][j]=0;
            else
                dp[0][j]=INT_MAX;
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
            }
        }
        
        return dp[m][n];
     
    }
};
