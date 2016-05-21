/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
  [3, 0,  1,  4,  2]
  [5, 6,  3,  2,  1]
  [1, 2*, 0*, 1*, 5]
  [4, 1*, 0*, 1*, 7]
  [1, 0*, 3*, 0*, 5]
Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]
sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10

Note:
The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

// T : O(MN), S : O(MN), update : O(N), query : O(M)
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        for(int i = 0; i < matrix.size(); i++)
            hash.push_back(vector<int>(matrix[0].size() + 1, 0));
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                hash[i][j + 1] = hash[i][j] + matrix[i][j]; //sum for this row only
    }

    void update(int row, int col, int val) {
        int diff = val - (hash[row][col + 1] - hash[row][col]);
        for(int i = col + 1; i < hash[row].size(); i++)
            hash[row][i] += diff;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++)
            sum += (hash[i][col2 + 1] - hash[i][col1]);
        return sum;
    }
private:
    vector<vector<int>> hash;
};

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
