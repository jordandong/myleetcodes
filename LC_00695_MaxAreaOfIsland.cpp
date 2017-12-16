/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.)
You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6.
Note the answer is not 11, because the island must be connected 4-directionally.

Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.

Note: The length of each dimension in the given grid does not exceed 50.
*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        int res = 0, sol = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sol = 0;
                if (grid[i][j])
                    maxAreaOfIslandHelper(grid, i, j, sol, res);
            }
        }
        return res;
    }
private:
    void maxAreaOfIslandHelper(vector<vector<int>>& grid, int x, int y, int &sol, int &res) {
        int m = grid.size(), n = grid[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0)
            return;
        grid[x][y] = 0;
        res = max(res, ++sol);
        maxAreaOfIslandHelper(grid, x - 1, y, sol, res);
        maxAreaOfIslandHelper(grid, x + 1, y, sol, res);
        maxAreaOfIslandHelper(grid, x, y - 1, sol, res);
        maxAreaOfIslandHelper(grid, x, y + 1, sol, res);
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j])
                    res = max(res, maxAreaOfIslandHelper(grid, i, j));
            }
        }
        return res;
    }
private:
    int maxAreaOfIslandHelper(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size(), n = grid[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0)
            return 0;
        grid[x][y] = 0;
        return maxAreaOfIslandHelper(grid, x - 1, y) +
               maxAreaOfIslandHelper(grid, x + 1, y) +
               maxAreaOfIslandHelper(grid, x, y - 1) +
               maxAreaOfIslandHelper(grid, x, y + 1) + 1;
    }
};
