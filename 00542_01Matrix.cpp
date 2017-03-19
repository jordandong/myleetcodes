/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size();
        if (M == 0)
            return {{}};
        int N = matrix[0].size();
        if (N == 0)
            return {{}};
        vector<vector<int>> res(M, vector<int>(N, INT_MAX));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == 0) {
                    res[i][j] = 0;
                    updateMatrixHelper(matrix, i + 1, j, 0, res);
                    updateMatrixHelper(matrix, i - 1, j, 0, res);
                    updateMatrixHelper(matrix, i, j + 1, 0, res);
                    updateMatrixHelper(matrix, i, j - 1, 0, res);
                }
            }
        }
        return res;
    }
private:
    void updateMatrixHelper(vector<vector<int>>& matrix, int x, int y, int dis, vector<vector<int>>& res) {
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || matrix[x][y] == 0)
            return;
        if (res[x][y] <= dis + 1)
            return;
        res[x][y] = dis + 1;
        updateMatrixHelper(matrix, x - 1, y, dis + 1, res);
        updateMatrixHelper(matrix, x + 1, y, dis + 1, res);
        updateMatrixHelper(matrix, x, y - 1, dis + 1, res);
        updateMatrixHelper(matrix, x, y + 1, dis + 1, res);
    }
};
