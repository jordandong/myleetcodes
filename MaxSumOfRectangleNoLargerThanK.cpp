/*
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:
Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2
The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

Note:
The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?

Hide Tags Binary Search Queue
*/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {    
        int M = matrix.size();
        if (M == 0)
            return 0;
        int N = matrix[0].size();
        if (N == 0)
            return 0;
            
        bool flag = false;
        if (M > N) {
            swap(M, N);
            flag = true;
        }
            
        int res = INT_MIN;
        for (int up = 0; up < M; up++) { //O(M)
            vector<int> col_sum(N, 0);
            for (int down = up; down < M; down++) { //O(M)
                for (int j = 0; j < N; j++)
                    col_sum[j] += flag ? matrix[j][down] : matrix[down][j];
                    
                // Find the max subarray no more than K 
                set<int> squareSet;
                squareSet.insert(0);
                int curSum = 0, curMax = INT_MIN;
                for (int sum : col_sum) { //O(N)
                    curSum += sum;
                    auto it = squareSet.lower_bound(curSum - k);//O(logN)
                    if (it != squareSet.end())
                        curMax = max(curMax, curSum - *it);
                squareSet.insert(curSum);
            }
            res = max(res, curMax);
            }
        }
        return res;
    }
};
