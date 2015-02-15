/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

Hide Tags Array Binary Search
*/

//T:O(2* logN)
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        if(n == 0)
            return false;
        
        int lo = 0;
        int hi = m - 1;
        int r = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(matrix[mid][n - 1] == target)
                return true;
            if(matrix[mid][n - 1] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        if(lo == m)
            return false;
        
        r = lo;
        lo = 0;
        hi = n - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(matrix[r][mid] == target)
                return true;
            if(matrix[r][mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return false;
    }
};

//T:O(2 * N)
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int M = matrix.size();
        if (M == 0)
        	return false;
        int N = matrix[0].size();
        if (N == 0)
        	return false;
        	
        if(target < matrix[0][0] || target > matrix[M-1][N-1])
        	return false;

        int i = 0, j = N - 1;
        while (i < M && j >= 0) {
            if (matrix[i][j] < target)
            	i++;
            else if (matrix[i][j] > target)
            	j--;
            else 
            	return true;
        }
        return false;
    }
};
