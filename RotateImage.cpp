//============================================================================
// Rotate Image
// You are given an n x n 2D matrix representing an image.
//
// Rotate the image by 90 degrees (clockwise).
//
// Follow up:
// Could you do this in-place?
//============================================================================

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int layer = 1;
        clockwise(matrix, layer);
    }
    
    void clockwise(vector<vector<int> > &matrix, int layer){
        if(layer>matrix.size()/2)
            return;
        int n = matrix.size(); 
        for(int i=layer-1; i<n-layer; i++){
            int tmp = matrix[layer-1][i];
            //left to top
            matrix[layer-1][i] = matrix[n-1-i][layer-1];
            //bottom to left
            matrix[n-1-i][layer-1] = matrix[n-layer][n-1-i];
            //right to bottom
            matrix[n-layer][n-1-i] = matrix[i][n-layer];
            //top to right
            matrix[i][n-layer] = tmp;
        }
        clockwise(matrix, layer+1);
    }
};


#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int j = 0; j < n/2; ++j) {
            int first = j;
            int last = n - j - 1;
            for (int i = first; i < last; ++i) {
                int offset = i - first;
                int top = matrix[first][i];  // save top
                //left -> top
                matrix[first][i] = matrix[last-offset][first];
                //bottom -> left
                matrix[last-offset][first] = matrix[last][last-offset];
                //right -> bottom
                matrix[last][last-offset] = matrix[i][last];
                //top -> right
                matrix[i][last] = top;
            }
        }
    }
};

int main() {
    return 0;
}
