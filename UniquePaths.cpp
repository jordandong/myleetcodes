/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Hide Tags Array Dynamic Programming
*/

//optimize space use
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m ==0 || n==0)
            return 0;  
        vector<int> maxV(n, 0);  
        maxV[0] = 1;  
        for(int i = 0; i<m; i++){
            for(int j = 1; j<n; j++)
                    maxV[j] = maxV[j-1] + maxV[j];  //dp[i][j] = dp[i][j-1] + dp[i-1][j]
        }  
        return maxV[n-1];  
    }
};
