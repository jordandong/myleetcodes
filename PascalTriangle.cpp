//============================================================================
// Pascal's Triangle
// Given numRows, generate the first numRows of Pascal's triangle.
//
// For example, given numRows = 5,
// Return
//
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int> > generate(int numRows)
    {
        vector<vector<int> > res;
        if (numRows < 1)
        	return res;
        res.reserve(numRows);
        res.push_back(vector<int>(1, 1));
        
        int m = 1;
        while (m < numRows)
        {
            vector<int> row;
            row.reserve(m+1);
            row.push_back(1);
            for (int i = 0; i < m-1; i++)
                row.push_back(res[m-1][i] + res[m-1][i+1]);
            row.push_back(1);
            res.push_back(row);
            m++;
        }
        return res;
    }
};

int main()
{
    return 0;
}


//11^n should be the results, but overflow, so small n is fine
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        if(numRows==0)
            return res;
        
        for(int i=0;i<numRows;i++){
            vector<int> row;
            for(int j=0;j<=i;j++){
                if(i==0&&j==0){
                    row.push_back(1);
                }
                else if(j==0){
                    row.push_back(0+res[i-1][j]);
                }
                else if(j==i){
                    row.push_back(0+res[i-1][i-1]);
                }
                else{
                    row.push_back(res[i-1][j-1]+res[i-1][j]);
                }
            }
            res.push_back(row);
        }
        
        return res;
    }
};

