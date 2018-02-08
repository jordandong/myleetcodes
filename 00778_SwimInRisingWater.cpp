/*
On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?

Example 1:

Input: [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:

Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
Note:

2 <= N <= 50.
grid[i][j] is a permutation of [0, ..., N*N - 1].
*/

//O(N^2*logN), BS + DFS
class Solution {
private:
    int n, m;
    vector<vector<bool>> vis;

    void swimInWaterHelper(int i, int j, int v, vector<vector<int>> &grid) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] > v || vis[i][j])
            return;
        vis[i][j] = true;
        
        swimInWaterHelper(i + 1, j, v, grid);
        swimInWaterHelper(i - 1, j, v, grid);
        swimInWaterHelper(i, j + 1, v, grid);
        swimInWaterHelper(i, j - 1, v, grid);
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int lo = 0, hi = m * n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            vis = vector<vector<bool>>(m, vector<bool>(n, false));
            swimInWaterHelper(0, 0, mid, grid);
            if (vis[m - 1][n - 1])
                hi = mid;
            else
                lo = mid + 1;
        }
        return hi;
    }
};

//O(N^2*logN), BS + BFS
class Solution {
private:
    int n, m;
    vector<vector<bool>> vis;

    void swimInWaterHelper(int v, vector<vector<int>> &grid) {
        if (grid[0][0] > v)
            return;
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = true;
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();

            if (i + 1 < m && grid[i + 1][j] <= v && vis[i + 1][j] == false) {
                q.push({i + 1, j});
                vis[i + 1][j] = true;
            }
            if (0 <= i - 1 && grid[i - 1][j] <= v && vis[i - 1][j] == false) {
                q.push({i - 1, j});
                vis[i - 1][j] = true;
            }
            if (j + 1 < n && grid[i][j + 1] <= v && vis[i][j + 1] == false) {
                q.push({i, j + 1});
                vis[i][j + 1] = true;
            }
            if (0 <= j - 1 && grid[i][j - 1] <= v && vis[i][j - 1] == false) {
                q.push({i, j - 1});
                vis[i][j - 1] = true;
            }
        }
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int lo = 0, hi = m * n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            vis = vector<vector<bool>>(m, vector<bool>(n, false));
            swimInWaterHelper(mid, grid);
            if (vis[m - 1][n - 1])
                hi = mid;
            else
                lo = mid + 1;
        }
        return hi;
    }
};

//O(N^3), DFS only
class Solution {
private:
    int n, m;
    vector<vector<bool>> vis;

    void swimInWaterHelper(int i, int j, int v, vector<vector<int>> &grid) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] > v || vis[i][j])
            return;
        vis[i][j] = true;
        
        swimInWaterHelper(i + 1, j, v, grid);
        swimInWaterHelper(i - 1, j, v, grid);
        swimInWaterHelper(i, j + 1, v, grid);
        swimInWaterHelper(i, j - 1, v, grid);
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int v = 0; v < n * m; v++) {
            vis = vector<vector<bool>>(m, vector<bool>(n, false));
            swimInWaterHelper(0, 0, v, grid);
            if (vis[m - 1][n - 1])
                return v;
        }
        return -1;
    }
};
