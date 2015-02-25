/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

Hide Tags Array
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
            
        for(int i = 1; i <= rowIndex; i++){
            res.push_back(0);
            for(int j = res.size() - 1; j>=1; j--)
                res[j] += res[j-1]; 
        }
        return res;
    }
};

class Solution{
public:
    vector<int> getRow(int rowIndex){
        vector<int> res;
        res.reserve(rowIndex + 1);
        res.push_back(1);
        if(rowIndex < 1)
        	return res;
        res.push_back(1);
        int m = 1;
        while(m < rowIndex){
            for(int i = 0; i < m; i++)
                res[i] += res[i + 1];
            res.insert(res.begin(), 1);
            m++;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res[2];
        int c = 0;
        res[c].push_back(1);
            
        for(int i = 1; i <= rowIndex; i++){
            res[c].push_back(0);
            res[c^1].push_back(1);
            for(int j = 1; j < res[c].size(); j++)
                res[c^1].push_back(res[c][j] + res[c][j-1]);
            res[c].clear();
            c ^= 1;
        }
        return res[c];
    }
};
