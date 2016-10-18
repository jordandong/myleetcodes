/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

Hide Tags Array
*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        if(m == 0)
            return;
        int n = matrix[0].size();
        if(n == 0)
            return;
        bool last_flag = false;
        bool curr_flag = false;

        for(int i = 0; i < m; i++){
            curr_flag = false;
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    int r = i;
                    while(r > 0)
                        matrix[--r][j] = 0;//reset all row in this col
                    curr_flag = true;
                }else{
                    if(i > 0 && matrix[i-1][j] == 0) //reset if last row is zero
                        matrix[i][j] = 0;
                    if(last_flag) //reset last row if last row reset flag is set
                        matrix[i-1][j] = 0;
                }
            }
            last_flag = curr_flag;
        }
        
        if(last_flag){//reset last row
            for(int j = 0; j < n; j++)
                matrix[m-1][j] = 0;
        }
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool col[n];
        memset(col, false, sizeof(bool)*n);
            
        for(int i = 0; i < m; i++){
            int k = 0;
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    col[j] = true;
                    while(k <= j) //set the left part of col j on row i
                        matrix[i][k++] = 0;
                }
            }
            if(k != 0){ //set the right part of curr row i
                while(k < n)
                    matrix[i][k++] = 0;
            }
        }
        
        for(int c = 0; c < n; c++){
            if(col[c]){
                for(int p = 0; p < m; p++)//set col which has zero
                    matrix[p][c] = 0;
            }
        }
    }
};

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
                if(matrix[i][j] == 0) 
                    matrix[0][j] = matrix[i][0] = 0; //using first row/col to record the zeros in beyond (1, 1)
            }
        }
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(firstRow) {
            for(int j = 0; j < col; j++)
                matrix[0][j] = 0;
        }
        if(firstCol) {
            for(int i = 0; i < row; i++)
                matrix[i][0] = 0;
        }
    }
};
