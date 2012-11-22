//============================================================================
// Set Matrix Zeroes
// Given a m x n matrix, if an element is 0, set its entire row and column to
// 0. Do it in place.
//
// Follow up:
// Did you use extra space?
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?
//============================================================================

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        int n = matrix[0].size();
        bool col[n];
        int r=0;
        while(r<n)
            col[r++]=false;
            
        for(int i=0;i<m;i++){
            int k = 0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    col[j]=true;
                    while(k<=j){
                        matrix[i][k]=0;
                        k++;
                    }
                }
            }
            if(k!=0){
                    while(k<n){
                        matrix[i][k]=0;
                        k++;
                    }
            }
        }
        
        for(int l=0;l<n;l++){
            if(col[l]){
                for(int p=0; p<m;p++)
                    matrix[p][l]=0;
            }
        }
    }
};


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool firstRow = false;
        bool firstCol = false;
        for(int i = 0; i < row; i++) {
            if(matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }
        for(int i = 0; i < col; i++) {
            if(matrix[0][i] == 0) {
                firstRow = true;
                break;
            }
        }
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(firstRow) {
            for(int j = 0; j < col; j++) {
                matrix[0][j] = 0;
            }
        }
        if(firstCol) {
            for(int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
	return 0;
}
