/*
We have a grid of 1s and 0s; the 1s in a cell represent bricks.  A brick will not drop if and only if it is directly connected to the top of the grid, or at least one of its (4-way) adjacent bricks will not drop.

We will do some erasures sequentially. Each time we want to do the erasure at the location (i, j), the brick (if it exists) on that location will disappear, and then some other bricks may drop because of that erasure.

Return an array representing the number of bricks that will drop after each erasure in sequence.

Example 1:
Input: 
grid = [[1,0,0,0],[1,1,1,0]]
hits = [[1,0]]
Output: [2]
Explanation: 
If we erase the brick at (1, 0), the brick at (1, 1) and (1, 2) will drop. So we should return 2.
Example 2:
Input: 
grid = [[1,0,0,0],[1,1,0,0]]
hits = [[1,1],[1,0]]
Output: [0,0]
Explanation: 
When we erase the brick at (1, 0), the brick at (1, 1) has already disappeared due to the last move. So each erasure will cause no bricks dropping.  Note that the erased brick (1, 0) will not be counted as a dropped brick.
 

Note:

The number of rows and columns in the grid will be in the range [1, 200].
The number of erasures will not exceed the area of the grid.
It is guaranteed that each erasure will be located inside the grid.
An erasure may refer to a location with no brick - if it does, no bricks drop.
*/

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size();
        if (m == 0)
            return {};
        int n = grid[0].size();
        if (n == 0)
            return {};
        int k = hits.size();
        if (k == 0)
            return {};
        
        //remove the brick count if it is there or not
        for (auto h: hits)
            grid[h[0]][h[1]] -= 1;
        
        //color the stable bricks connecting to the top
        for (int j = 0; j < n; j++)
            hitBricksHelper(0, j, grid);
        
        //add hit brick back to see if we can attach more bricks to the stable bricks 
        vector<int> ans(k, 0);
        for (int i = k - 1; i >= 0; i--) {
            if (grid[hits[i][0]][hits[i][1]] == -1)
                continue; //empty at beginning
            grid[hits[i][0]][hits[i][1]] += 1; //add brick back
            if (!toTop(hits[i][0], hits[i][1], grid))
                continue;
            ans[i] = hitBricksHelper(hits[i][0], hits[i][1], grid) - 1; //don't count the hit one
        }
        
        return ans;
    }

private:
    int hitBricksHelper(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != 1)
            return 0;
        int cnt = 1;
        grid[r][c] = 2; //mark stable
        cnt += hitBricksHelper(r - 1, c, grid);
        cnt += hitBricksHelper(r + 1, c, grid);
        cnt += hitBricksHelper(r, c - 1, grid);
        cnt += hitBricksHelper(r, c + 1, grid);
        return cnt;
    }
    
    bool toTop(int i, int j, vector<vector<int>>& grid) {
        return ( (i == 0) ||
                 (i - 1 >= 0 && grid[i - 1][j] == 2) || 
                 (i + 1 < grid.size() && grid[i + 1][j] == 2) ||
                 (j - 1 >= 0 && grid[i][j - 1] == 2) ||
                 (j + 1 < grid[0].size() && grid[i][j + 1] == 2));
    }
};
