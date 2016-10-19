/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

Hide Tags Array Dynamic Programming
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {  
        int m = obstacleGrid.size();  
        if(m == 0)
            return 0;  
        int n = obstacleGrid[0].size();  
        if(n == 0 || obstacleGrid[0][0] == 1)
            return 0;  
        vector<int> maxV(n, 0);  
        maxV[0] =1;  
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){  
                if(obstacleGrid[i][j] ==1)  
                    maxV[j] = 0;  
                else if(j >0)  
                    maxV[j] = maxV[j-1] + maxV[j];  //dp[i][j] = dp[i][j-1] + dp[i-1][j]
            }  
        }  
        return maxV[n-1];  
    } 
};
