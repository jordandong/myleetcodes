/*
Given a 01 matrix M, find the longest line of consecutive one in the matrix.
The line could be horizontal, vertical, diagonal or anti-diagonal.

Example:
Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3

Hint: The number of elements in the given matrix will not exceed 10,000.
*/

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int R = M.size();
        if (R == 0)
            return 0;
        int C = M[0].size();
        if (C == 0)
            return 0;
        vector<int> col(C, 0), anti_diag(C, 0);
        vector<vector<int>> diag(2, vector<int>(C, 0));
        int row = 0, mx = 0;
        for (int i = 0 ; i < R; i++) {
            row = 0;
            for (int j = 0; j < C; j++) {
                if (M[i][j] == 0) {
                    row = 0;
                    col[j] = 0;
                    anti_diag[j] = 0;
                    diag[i % 2][j] = 0;
                } else {
                    row++;
                    col[j]++;
                    anti_diag[j] = ((j == (C - 1)) ? 1 : anti_diag[j + 1] + 1);
                    diag[i % 2][j] = ((j == 0) ? 1 : diag[(i + 1) % 2][j - 1] + 1);
                }
                mx = max(mx, max(row, max(col[j], max(diag[i % 2][j], anti_diag[j]))));
            }
        }
        return mx;
    }
};

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int R = M.size();
        if (R == 0)
            return 0;
        int C = M[0].size();
        if (C == 0)
            return 0;
        vector<int> col(C, 0), diag(C, 0), anti_diag(C, 0);
        int row = 0, mx = 0;
        for (int i = 0 ; i < R; i++) {
            row = 0;
            for (int j = 0; j < C; j++) {
                if (M[i][j] == 0) {
                    row = 0;
                    col[j] = 0;
                    anti_diag[j] = 0;
                } else {
                    row++;
                    col[j]++;
                    anti_diag[j] = ((j == (C - 1)) ? 1 : anti_diag[j + 1] + 1);
                }
                mx = max(mx, max(row, max(col[j], anti_diag[j])));
            }
            for (int j = C - 1; j >= 0; j--) {
                if (M[i][j] == 0) {
                    diag[j] = 0;
                } else {
                    diag[j] = ((j == 0) ? 1 : diag[j - 1] + 1);
                }
                mx = max(mx, diag[j]);
            }

        }
        return mx;
    }
};
