//============================================================================
// Search a 2D Matrix
// Write an efficient algorithm that searches for a value in an m x n matrix.
// This matrix has the following properties:
//
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// For example,
//
// Consider the following matrix:
//
// [
//  [1,   3,  5,  7],
//  [10, 11, 16, 20],
//  [23, 30, 34, 50]
// ]
//Given target = 3, return true.
//============================================================================

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        int n = matrix[0].size();
        int row = BSTrow(matrix, 0, m-1, m, n, target);
        if(row<0)
            return false;
        else
            return BSTcol(matrix, 0, n-1 , row, target);
            //return true;
    }
    
    int BSTrow(vector<vector<int> > &matrix, int m1, int m2, int m, int n, int target){
        if(m1>m2)
            return -1;
        if(m1<0)
            return 0;
            
        if(m1==m2){
            return m1;
        }
        int mid = (m1 + m2)/2;
            
        if(matrix[mid][n-1]>target)
            return BSTrow(matrix, m1, mid, m, n, target);
        else if(matrix[mid][n-1]<target)
            return BSTrow(matrix, mid+1, m2, m, n, target);
        else if(matrix[mid][n-1]==target)
            return mid;
    }
    
    bool BSTcol(vector<vector<int> > &matrix, int n1, int n2, int row, int target){
        if(n1>n2)
            return false;
            
        int mid = (n1 + n2)/2;
        
        if(n1==n2){
            return matrix[row][n1]==target;
        }
            
        if(matrix[row][mid]>target)
            return BSTcol(matrix, n1, mid-1, row, target);
        else if(matrix[row][mid]<target)
            return BSTcol(matrix, mid+1, n2, row, target);
        else if(matrix[row][mid]==target)
            return true;
    }
};





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int M = matrix.size();
        if (M == 0)
        	return false;
        int N = matrix[0].size();
        if (N == 0)
        	return false;
        	
        if (target < matrix[0][0] || target > matrix[M-1][N-1])
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

int main() {
    return 0;
}
