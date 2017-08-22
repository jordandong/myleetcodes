/*
Given a 2D integer matrix M representing the gray scale of an image,
you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself.
If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]

Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]

Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0

Note:
1. The value in the given matrix is in the range of [0, 255].
2. The length and width of the given matrix are in the range of [1, 150].
*/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size();
        if (m == 0)
            return {};
        int n = M[0].size();
        if (n == 0)
            return {};
        vector<vector<int>> res = M;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = getGray(i, j, M);
            }
        }
        return res;
    }

private:    
    int getGray(int x, int y, vector<vector<int>>& M) {
        int sum = 0, cnt = 0;
        for (int i = -1; i <= 1; i++) {
            if (x + i < 0 || x + i >= M.size())
                continue;
            for (int j = -1; j <= 1; j++) {
                 if (y + j < 0 || y + j >= M[0].size())
                    continue;
                sum += M[x + i][y + j];
                cnt++;
            }
        }
        return sum / cnt;
    }
};
