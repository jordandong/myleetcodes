/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally).
The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1.
The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:
一口一一
口口口一
一口一一
口口一一

Hide Tags Hash Table
*/


//T : O(M*N), S : O(1)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int M = grid.size();
        if (M == 0)
            return 0;
        int N = grid[0].size();
        if (N == 0)
            return 0;
        int res = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j]) {
                    if (i == 0 || grid[i - 1][j] == 0)
                        res++;
                    if (i == M - 1 || grid[i + 1][j] == 0)
                        res++;
                    if (j == 0 || grid[i][j  - 1] == 0)
                        res++;
                    if (j == N - 1 || grid[i][j + 1] == 0)
                        res++;
                }
            }
        }
        return res;
    }
};
