/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

Hide Tags Array
*/

//non recursion
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));
        int x = 1;
        int offset = 0;
        while(n > 0){
            if(n == 1){
                for(int j = 0; j < n; j++)
                    res[offset][offset + j] = x++;
                return res;
            }
            
            int i = 0, j = 0;
            while(j < n - 1)
        	    res[offset + i][offset + j++] = x++;
            while(i < n - 1)
        	    res[offset + i++][offset + j] = x++;
            while(j > 0)
        	    res[offset + i][offset + j--] = x++;
            while(i > 0)
        	    res[offset + i--][offset + j] = x++;
        	n -= 2;
        	offset += 1;
        }
        return res;
    }
};

//recursion
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res;
        for (int i = 0; i < n; i++)
            res.push_back(vector<int>(n, 0));
        generateMatrixHelper(res, 1, n, 0);
        return res;
    }
    
    void generateMatrixHelper(vector<vector<int> > &res, int x, int n, int k) {
        if (n <= 0)
            return;
        if (n == 1) {
            res[k+n-1][k+n-1] = x++;
            return;
        }
        
        int i = 0, j = 0;
        for (; j < n-1; j++)
            res[k+i][k+j] = x++;
        for (; i < n-1; i++)
            res[k+i][k+j] = x++;
        for (; j > 0; j--)
            res[k+i][k+j] = x++;
        for (; i > 0; i--)
            res[k+i][k+j] = x++;
        generateMatrixHelper(res, x, n-2, k+1);
    }
};
