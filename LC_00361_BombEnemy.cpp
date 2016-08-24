/*
Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.

Example:
For the given grid
0 E 0 0
E 0 W E
0 E 0 0
return 3. (Placing a bomb at (1,1) kills 3 enemies)
In the example, if you put a bomb at (1,1) you will kill 3 enemies which is the best you can get. You can not kill the guy behind the wall at (1,3).
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <queue>
using namespace std;

//T : O(MN), S : O(N)
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int M = grid.size(), N = M ? grid[0].size() : 0;
        int res = 0, row, col[N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (j == 0 || grid[i][j - 1] == 'W') {
                    row = 0;
                    for (int k = j; k < N && grid[i][k] != 'W'; k++)
                        row += grid[i][k] == 'E';
                }
                if (i == 0 || grid[i - 1][j] == 'W') {
                    col[j] = 0;
                    for (int k = i; k < M && grid[k][j] != 'W'; k++)
                        col[j] += grid[k][j] == 'E';
                }
                if (grid[i][j] == '0')
                    res = max(res, row + col[j]);
            }
        }
        return res;
    }
};

//T : O(MN), S : O(MN + N)
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int res = 0;
        if (grid.empty() || grid[0].empty())
            return res;

        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> col(M, vector<int>(N));
        vector<vector<int>> row(M, vector<int>(N));
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (grid[i][j] != 'W') {
                    if (i + 1 < M)
                        col[i][j] = col[i + 1][j];

                    if (j + 1 < N)
                        row[i][j] = row[i][j + 1];
                    
                    if (grid[i][j] == 'E') {
                        ++col[i][j];
                        ++row[i][j];
                    }
                }
            }
        }

        int left = 0;
        vector<int> up(grid[0].size());
        for (int i = 0; i < M; ++i) {
            left = 0;
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 'W') {
                    up[j] = 0;
                    left = 0;
                } else if (grid[i][j] == 'E') {
                    ++up[j];
                    ++left;
                } else {
                    res = max(res, left + up[j] + col[i][j] + row[i][j]);
                }
            }
        }
        return res;
    }
};

//T : O(MN), S : O(MN)
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int res = 0;
        if (grid.empty() || grid[0].empty())
            return res;

        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> col(M, vector<int>(N));
        vector<vector<int>> row(M, vector<int>(N));
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (grid[i][j] != 'W') {
                    if (i + 1 < M)
                        col[i][j] = col[i + 1][j];

                    if (j + 1 < N)
                        row[i][j] = row[i][j + 1];
                    
                    if (grid[i][j] == 'E') {
                        ++col[i][j];
                        ++row[i][j];
                    }
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                sum = col[i][j] + row[i][j];
                col[i][j] = 0;
                row[i][j] = 0;
                if (grid[i][j] != 'W') {
                    if (i - 1 >= 0)
                        col[i][j] = col[i - 1][j];

                    if (j - 1 >= 0)
                        row[i][j] = row[i][j - 1];
                    
                    if (grid[i][j] == 'E') {
                        ++col[i][j];
                        ++row[i][j];
                    }
                    if (grid[i][j] == '0')
                        res = max(res, sum + col[i][j] + row[i][j]);
                }
            }
        }
        return res;
    }
};

int main(void) {
    vector<vector<char>> data = {{'0','E','0','0'}, {'E','0','W','E'}, {'0','E','0','0'}};
    Solution sol;
    cout<<sol.maxKilledEnemies(data)<<endl;
    return 0;
}

3
