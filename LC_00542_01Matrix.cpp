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
1. The number of elements of the given matrix will not exceed 10,000.
2. There are at least one 0 in the given matrix.
3. The cells are adjacent in only four directions: up, down, left and right.

Hide Tags Depth-first Search Breadth-first Search
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        queue<int> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    q.push(10000 *i + j);
                    res[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            int i = q.front() / 10000;
            int j = q.front() % 10000;
            q.pop();
            if (i > 0) {
                if (res[i - 1][j] == INT_MAX)
                    q.push(10000 * (i - 1) + j);
                res[i - 1][j] = min(res[i - 1][j], res[i][j] + 1);
            }
            if (i < m - 1) {
                if (res[i + 1][j] == INT_MAX)
                    q.push(10000 * (i + 1) + j);
                res[i + 1][j] = min(res[i + 1][j], res[i][j] + 1);
            }
            if (j > 0) {
                if (res[i][j - 1] == INT_MAX)
                    q.push(10000 * i + j - 1);
                res[i][j - 1] = min(res[i][j - 1], res[i][j] + 1);
            }
            if (j < n - 1) {
                if (res[i][j + 1] == INT_MAX)
                    q.push(10000 * i + j + 1);
                res[i][j + 1] = min(res[i][j + 1], res[i][j] + 1);
            }
        }
        return res;
    }
};
