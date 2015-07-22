/*
Search a 2D Matrix II Total Accepted: 438 Total Submissions: 1478 My Submissions Question Solution 
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

For example,
Consider the following matrix:
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.
Given target = 20, return false.

Hide Tags Divide and Conquer Binary Search
*/

//T : O(m + n), S : O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size();
        if (M == 0)
            return false;
        int N = matrix[0].size();
        if (N == 0)
            return false;
        int i = 0;
        int j = N - 1;
        while ( i < M && j >=0) {
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] < target)
                i++;
            else
                j--;
        }
        return false;
    }
};

//T : O(mlogm + nlogn), S : O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size();
        if(M == 0)
            return false;
        int N = matrix[0].size();
        if(N == 0)
            return false;
        int i = 0;
        int j = N - 1;
        while (i < M && j >= 0) {
            i =  row_search(matrix, target, i, M - 1, j);
            if (i == -10)
                return true;
            if (i == M)
                return false;   	
            j =  col_search(matrix, target, 0, j, i);
            if (j == -10)
                return true;
            if (j < 0)
                return false;   	
        }
        return false;
    }

    int row_search(vector<vector<int>>& matrix, int target, int lo, int hi, int j) {
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (matrix[mid][j] == target)
                return -10;
            if(matrix[mid][j] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    int col_search(vector<vector<int>>& matrix, int target, int lo, int hi, int i) {
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(matrix[i][mid] == target)
                return -10;
            if(matrix[i][mid] > target){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        return hi;
    }
};
