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

// Time:  ctor:   O(m * n),
//        update: O(logm + logn),
//        query:  O(logm + logn)
// Space: O(m * n)

// Segment Tree solution.
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) : matrix_(matrix) {
        if (!matrix.empty() && !matrix[0].empty()) {
            const int m = matrix.size();
            const int n =  matrix[0].size();
            root_ = buildHelper(matrix,
                                make_pair(0, 0),
                                make_pair(m - 1, n - 1));
        }
    }

    void update(int row, int col, int val) {
        if (matrix_[row][col] != val) {
            matrix_[row][col] = val;
            updateHelper(root_, make_pair(row, col), val);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumRangeHelper(root_, make_pair(row1, col1), make_pair(row2, col2));
    }

private:
    vector<vector<int>>& matrix_;

    class SegmentTreeNode {
    public:
        pair<int, int> start, end;
        int sum;
        vector<SegmentTreeNode *> neighbor;
        SegmentTreeNode(const pair<int, int>& i, const pair<int, int>& j, int s) : 
            start(i), end(j), sum(s) {
        }
    };

    SegmentTreeNode *root_;

    // Build segment tree.
    SegmentTreeNode *buildHelper(const vector<vector<int>>& matrix,
                                 const pair<int, int>& start,
                                 const pair<int, int>& end) {
        if (start.first > end.first || start.second > end.second) {
            return nullptr;
        }

        // The root's start and end is given by build method.
        SegmentTreeNode *root = new SegmentTreeNode(start, end, 0);

        // If start equals to end, there will be no children for this node.
        if (start == end) {
            root->sum = matrix[start.first][start.second];
            return root;
        }

        int mid_x = (start.first + end.first) / 2;
        int mid_y = (start.second + end.second) / 2;
        root->neighbor.emplace_back(buildHelper(matrix, start, make_pair(mid_x, mid_y)));
        root->neighbor.emplace_back(buildHelper(matrix, make_pair(start.first, mid_y + 1), make_pair(mid_x, end.second)));
        root->neighbor.emplace_back(buildHelper(matrix, make_pair(mid_x + 1, start.second), make_pair(end.first, mid_y)));
        root->neighbor.emplace_back(buildHelper(matrix, make_pair(mid_x + 1, mid_y + 1), end));
        for (auto& node : root->neighbor) {
            if (node) {
                root->sum += node->sum;
            }
        }
        return root;
    }

    void updateHelper(SegmentTreeNode *root, const pair<int, int>& i, int val) {
        // Out of range.
        if (root == nullptr ||
            (root->start.first > i.first || root->start.second > i.second) ||
            (root->end.first < i.first || root->end.second < i.second)) {
            return;
        }

        // Change the node's value with [i] to the new given value.
        if ((root->start.first == i.first && root->start.second == i.second) &&
            (root->end.first == i.first && root->end.second == i.second)) {
            root->sum = val;
            return;
        }
        for (auto& node : root->neighbor) {
            updateHelper(node, i, val);
        }

        root->sum = 0;
        for (auto& node : root->neighbor) {
            if (node) {
                root->sum += node->sum;
            }
        }
    }
    
    int sumRangeHelper(SegmentTreeNode *root, const pair<int, int>& start, const pair<int, int>& end) {
        // Out of range.
        if (root == nullptr ||
            (root->start.first > end.first || root->start.second > end.second) ||
            (root->end.first < start.first || root->end.second < start.second)) {
            return 0;
        }

        // Current segment is totally within range [start, end]
        if ((root->start.first >= start.first && root->start.second >= start.second) &&
            (root->end.first <= end.first && root->end.second <= end.second)) {
            return root->sum;
        }
        int sum = 0;
        for (auto& node : root->neighbor) {
            if (node) {
                sum += sumRangeHelper(node, start, end);
            }
        }
        return sum;
    }
};
