/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

Hide Tags Array Dynamic Programming
*/

//did NOT change the input
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int N = triangle.size();
        int dp[N + 1];
        memset(dp, 0 ,sizeof(int)*(N + 1));
        while(N-- > 0)
            for(int i = 0; i <= N; ++i) 
                dp[i] = triangle[N][i] + min(dp[i], dp[i+1]);
        return dp[0];
    }
};

//change the input
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty())
        	return 0;
        int M = triangle.size();
        for(int i = M - 2; i >= 0; --i){
            int N = triangle[i].size();
            for (int j = 0; j < N; ++j)
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j+1]);
        }
        return triangle[0][0];
    }
};
