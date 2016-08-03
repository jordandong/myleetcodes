/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
return 13.

Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.

Hide Tags Binary Search Heap
Hide Similar Problems (M) Find K Pairs with Smallest Sums
*/

// T:  O(k * log(min(M, N, k))) , S: O(min(M, N, K))
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int kth_smallest = 0;
        using P = pair<int, pair<int, int>>;
        priority_queue<P, vector<P>, greater<P>> q;
        auto push = [&matrix, &q](int i, int j) {
            if (matrix.size() > matrix[0].size()) {
                if (i < matrix[0].size() && j < matrix.size()) {
                    q.emplace(matrix[j][i], make_pair(i, j));
                }
            } else {
                if (i < matrix.size() && j < matrix[0].size()) {
                    q.emplace(matrix[i][j], make_pair(i, j));
                }
            }
        };

        push(0, 0);
        while (!q.empty() && k--) {
            auto tmp = q.top(); q.pop();
            kth_smallest = tmp.first;
            int i, j;
            tie(i, j) = tmp.second;
            push(i, j + 1);
            if (j == 0) {
                push(i + 1, 0);
            }
        }
        return kth_smallest; 
    }
};
