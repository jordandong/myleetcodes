//============================================================================
// Unique Paths
// A robot is located at the top-left corner of a m x n grid (marked 'Start'
// in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot
// is trying to reach the bottom-right corner of the grid (marked 'Finish' in
// the diagram below).
//
// How many possible unique paths are there?
//============================================================================

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
            dp[i][0]=0;
        for(int j=0;j<=n;j++)
            dp[0][j]=0;
        dp[1][0]=1;  
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];        
        return dp[m][n];
        
    }
    
    int uniquePaths2(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int dp[2][n+1];
        for(int j=0;j<=n; j++)
            dp[0][j]=0;
        dp[0][1]=1;
        dp[1][0]=0;
        
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                dp[i%2][j] = dp[(i-1)%2][j] + dp[i%2][j-1];        
        
        return dp[m%2][n];    
    }
};


#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        memset(dp, 0, sizeof(int)*m*n);
        dp[0][0] = 1;
        for (int i = 1; i < m; i++)
        	dp[i][0] = dp[i-1][0];
        for (int j = 1; j < n; j++)
        	dp[0][j] = dp[0][j-1];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    return 0;
}
