//============================================================================
// Pascal's Triangle II
// Given an index k, return the kth row of the Pascal's triangle.
//
// For example, given k = 3,
// Return [1,3,3,1].
//
// Note:
// Could you optimize your algorithm to use only O(k) extra space?
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res;
        res.reserve(rowIndex+1);
        res.push_back(1);
        if (rowIndex < 1)
        	return res;
        res.push_back(1);
        int m = 1;
        while (m < rowIndex)
        {
            for (int i = 0; i < m; i++)
                res[i] += res[i+1];
            res.insert(res.begin(), 1);
            m++;
        }
        return res;
    }
};

int main()
{
    return 0;
}




class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        vector<int> extra;
        res.push_back(1);
            
        for(int i=1; i<=rowIndex; i++){
            res.push_back(0);
            extra = res;
            for(int j=1;j<res.size();j++)
                res[j] = res[j] + extra[j-1]; 
        }
        
        return res;
    }
};




class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        res.push_back(1);
            
        for(int i=1; i<=rowIndex; i++){
            res.push_back(0);
            for(int j=res.size()-1;j>=1;j--)
                res[j]+=res[j-1]; 
        }
        return res;
    }
};
