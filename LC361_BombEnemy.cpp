/*
TBD
We have a 2D grid. Each cell is either a wall, an enemy or empty.

For example (0-empty, X-enemy, Y-wall):
0 X 0 0
X 0 Y X
0 X 0 0
You have one bomb and you want to kill as many as possible enemies with it.
The bomb will kill all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.

Given such a grid, return the maximum enemies you can kill with one bomb.
Note that you can only put the bomb at empty cell.

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
                if (grid[i][j] != 'Y') {
                    if (i + 1 < M)
                        col[i][j] = col[i + 1][j];

                    if (j + 1 < N)
                        row[i][j] = row[i][j + 1];
                    
                    if (grid[i][j] == 'X') {
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
                if (grid[i][j] == 'Y') {
                    up[j] = 0;
                    left = 0;
                } else if (grid[i][j] == 'X') {
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
                if (grid[i][j] != 'Y') {
                    if (i + 1 < M)
                        col[i][j] = col[i + 1][j];

                    if (j + 1 < N)
                        row[i][j] = row[i][j + 1];
                    
                    if (grid[i][j] == 'X') {
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
                if (grid[i][j] != 'Y') {
                    if (i - 1 >= 0)
                        col[i][j] = col[i - 1][j];

                    if (j - 1 >= 0)
                        row[i][j] = row[i][j - 1];
                    
                    if (grid[i][j] == 'X') {
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
    vector<vector<char>> data = {{'0','X','0','0'}, {'X','0','Y','X'}, {'0','X','0','0'}};
    Solution sol;
    cout<<sol.maxKilledEnemies(data)<<endl;
    return 0;
}

3
