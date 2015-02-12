/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

Hide Tags Array
*/

/* flip left to right or up and down, then flip based on diag or back diag
 * 1 2 3     7 8 9    7 4 1
 * 4 5 6  -> 4 5 6 -> 8 5 2   or 
 * 7 8 9     1 2 3    9 6 3 

 * 1 2 3     9 6 3    7 4 1
 * 4 5 6  -> 8 5 2 -> 8 5 2  = clockwise
 * 7 8 9     7 4 1    9 6 3 

/* 1 2 3     3 2 1    3 6 9
 * 4 5 6  -> 6 5 4 -> 2 5 8   or 
 * 7 8 9     9 8 7    1 4 7 

 * 1 2 3     9 6 3    3 6 9
 * 4 5 6  -> 8 5 2 -> 2 5 8 = anti clockwise
 * 7 8 9     7 6 1    1 4 7 
*/

//T: O(N^2)
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int start = 0, end = m - 1;
        while(start < end){
            for(int j = 0; j < m; j++)
                swap(matrix[start][j], matrix[end][j]);
            start++;
            end--;
        }
        
        for(int i = 0; i < m; i++)
            for(int j = i + 1; j < m; j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};

//T: O(N^2 / 4)
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int j = 0; j < n/2; ++j) {
            int first = j;
            int last = n - j - 1;
            for(int i = first; i < last; ++i) {
                int offset = i - first;
                int top = matrix[first][i];  // save top
                //left -> top
                matrix[first][i] = matrix[last - offset][first];
                //bottom -> left
                matrix[last - offset][first] = matrix[last][last - offset];
                //right -> bottom
                matrix[last][last - offset] = matrix[i][last];
                //top -> right
                matrix[i][last] = top;
            }
        }
    }
};

//T: O(N^2 / 4)
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int layer = 1;
        clockwise(matrix, layer);
    }
    
    void clockwise(vector<vector<int> > &matrix, int layer){
        if(layer > matrix.size()/2)
            return;
        int n = matrix.size(); 
        for(int i = layer - 1; i < n - layer; i++){
            int tmp = matrix[layer-1][i];
            //left to top
            matrix[layer - 1][i] = matrix[n - 1 - i][layer - 1];
            //bottom to left
            matrix[n - 1 - i][layer - 1] = matrix[n - layer][n - 1 - i];
            //right to bottom
            matrix[n - layer][n - 1 - i] = matrix[i][n - layer];
            //top to right
            matrix[i][n - layer] = tmp;
        }
        clockwise(matrix, layer + 1);
    }
};
