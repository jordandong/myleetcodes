//============================================================================
// Unique Paths II
// Follow up for "Unique Paths":
//
// Now consider if some obstacles are added to the grids. How many unique
// paths would there be?
//
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
// For example,
// There is one obstacle in the middle of a 3x3 grid as illustrated below.
//
// [
//  [0,0,0],
//  [0,1,0],
//  [0,0,0]
// ]
// The total number of unique paths is 2.
//
// Note: m and n will be at most 100.
//============================================================================

//optimize space use
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {  
        int m = obstacleGrid.size();  
        if(m ==0)
            return 0;  
        int n = obstacleGrid[0].size();  
        if(obstacleGrid[0][0] ==1)
            return 0;  
        vector<int> maxV(n,0);  
        maxV[0] =1;  
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){  
                if(obstacleGrid[i][j] ==1)  
                    maxV[j]=0;  
                else if(j >0)  
                    maxV[j] = maxV[j-1]+maxV[j];  //dp[i][j] = dp[i][j-1] + dp[i-1][j]
            }  
        }  
        return maxV[n-1];  
    } 
};


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
            dp[i][0]=0;
        for(int j=0;j<=n;j++)
            dp[0][j]=0;
        dp[1][0]=1;  
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(obstacleGrid[i-1][j-1]==1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
                
        return dp[m][n];
    }
    
    int uniquePathsWithObstacles2(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[2][n+1];
        for(int j=0;j<=n; j++)
            dp[0][j]=0;
        dp[0][1]=1;
        dp[1][0]=0;
        
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                if(obstacleGrid[i-1][j-1]==1)
            		dp[i%2][j]=0;
            	else			
                	dp[i%2][j] = dp[(i-1)%2][j] + dp[i%2][j-1];
        return dp[m%2][n];

};

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0)
        	return 0;
        int n = obstacleGrid[0].size();
        if (n == 0)
        	return 0;
        if (obstacleGrid[0][0] == 1)
        	return 0;
        
        int dp[m][n];
        memset(dp, 0, sizeof(int)*m*n);
        dp[0][0] = 1;
        for (int i = 1; i < m; i++) {
            dp[i][0] = (obstacleGrid[i][0]) ? 0 : dp[i-1][0];
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = (obstacleGrid[0][j]) ? 0 : dp[0][j-1];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = (obstacleGrid[i][j]) ? 0 : dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    return 0;
}
