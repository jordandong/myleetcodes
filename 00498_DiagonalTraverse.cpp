/*
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order.

Example 1:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:

Note:
The total number of elements of the given matrix will not exceed 10,000.
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int M = matrix.size();
        if (M == 0)
            return {};
        int N = matrix[0].size();
        if (N == 0)
            return {};
        bool up = true; 
        int r = 0, c = 0;
        vector<int> res;
        while (r < M && c < N) {
            res.push_back(matrix[r][c]);
            if (up) {
                if (c == N - 1) {
                    r++;
                    up = false;
                } else if (r == 0) {
                    c++;
                    up = false;
                } else {
                    r--;
                    c++;
                }
            } else {
                if (r == M - 1) {
                    c++;
                    up = true;
                } else if (c == 0) {
                    r++;
                    up = true;
                } else {
                    r++;
                    c--;
                }
            }
        }
        return res;
    }
};
