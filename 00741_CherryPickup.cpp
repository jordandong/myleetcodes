/*
In a N x N grid representing a field of cherries, each cell is one of three possible integers.

0 means the cell is empty, so you can pass through;
1 means the cell contains a cherry, that you can pick up and pass through;
-1 means the cell contains a thorn that blocks your way.
Your task is to collect maximum number of cherries possible by following the rules below:

Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or down through valid path cells (cells with value 0 or 1);
After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells;
When passing through a path cell containing a cherry, you pick it up and the cell becomes an empty cell (0);
If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can be collected.
Example 1:
Input: grid =
[[0, 1, -1],
 [1, 0, -1],
 [1, 1,  1]]
Output: 5
Explanation: 
The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.
Note:

grid is an N by N 2D array, with 1 <= N <= 50.
Each grid[i][j] is an integer in the set {-1, 0, 1}.
It is guaranteed that grid[0][0] and grid[N-1][N-1] are not -1.
Discuss
*/

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size();
        int P_LEN = N + N - 1;
        vector<vector<int> > dp1 = vector<vector<int>>(N, vector<int>(N, -1));
        vector<vector<int> > dp2 = vector<vector<int>>(N, vector<int>(N, -1));
        dp1[0][0] = grid[0][0];
        dp2[0][0] = grid[0][0];
        
        for (int p = 2; p <= P_LEN; p++) {//p is the length of the path
            for (int x1 = 0; x1 < N; x1++) {
                for (int x2 = x1; x2 < N; x2++) {
                    int y1 = p - 1 - x1;
                    int y2 = p - 1 - x2;
                    if (y1 < 0 || y2 < 0 || y1 >= N || y2 >= N)
                        continue;
                    if (grid[y1][x1] < 0 || grid[y2][x2] < 0) {
                        dp2[x1][x2] = -1;
                        continue;
                    }   
                    int best = -1, delta = grid[y1][x1];
                    if (x1 != x2)
                        delta += grid[y2][x2];
                    if (x1 > 0 && x2 > 0 && dp1[x1 - 1][x2 - 1] >= 0) //from left left
                        best = max(best, dp1[x1 - 1][x2 - 1] + delta);
                    if (x1 > 0 && y2 > 0 && dp1[x1 - 1][x2] >= 0) //from left up
                        best = max(best, dp1[x1 - 1][x2] + delta);
                    if (y1 > 0 && x2 > 0 && dp1[x1][x2 - 1] >= 0) //from up left
                        best = max(best, dp1[x1][x2 - 1] + delta);
                    if (y1 > 0 && y2 > 0 && dp1[x1][x2] >= 0) //from up up
                        best = max(best, dp1[x1][x2] + delta);
                    dp2[x1][x2] = best;
                }
            }
            dp1 = dp2;
        }
        return dp1[N - 1][N - 1] < 0 ? 0 : dp1[N - 1][N - 1];
    }
};

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int d = grid.size(), p_len = 2 * d - 1;
        vector<vector<int>> state(d, vector<int>(d, -1));
        
        state[0][0] = grid[0][0];
        for (int p = 2; p <= p_len; ++p) {
            for (int x1 = min(p,d) - 1; x1 >= 0; --x1) {
                for (int x2 = min(p,d) - 1; x2 >= x1; --x2) {
                    int y1 = p - x1 - 1, y2 = p - x2 - 1;
                    if (y1 < 0 || y2 < 0 || y1 >= d || y2 >= d)
                        continue;
                    if (grid[y1][x1] == -1 || grid[y2][x2] == -1) {
                        state[x1][x2] = -1;
                        continue;
                    }
                    
                    int gain = (x1 == x2) ? grid[y1][x1] : grid[y1][x1] + grid[y2][x2];
                    int value = -1;
                    if (x1 - 1 >= 0 && state[x1 - 1][x2] >= 0) {
                        value = max(state[x1-1][x2] + gain, value);
                    }
                    
                    if (x2 - 1 >= 0 && state[x1][x2 - 1] >= 0) {
                        value = max(state[x1][x2-1] + gain, value);
                    }
                    
                    if (x1 - 1 >= 0 && x2 - 1 >= 0 && state[x1 - 1][x2 - 1] >= 0) {
                        value = max(state[x1 - 1][x2 - 1] + gain, value);
                    }
                    
                    if (state[x1][x2] >= 0) {
                        value = max(state[x1][x2] + gain, value);
                    }
                    state[x1][x2] = value;
                }
            }
        }
        return max(state[d - 1][d - 1], 0);
    }
};
