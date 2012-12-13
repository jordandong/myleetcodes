//============================================================================
// Given two integers n and k, return all possible combinations of k numbers
// out of 1 ... n.
//
// For example,
// If n = 4 and k = 2, a solution is:
//
//[
// [2,4],
// [3,4],
// [2,3],
// [1,2],
// [1,3],
// [1,4],
//]
//============================================================================

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        result.clear();
        vector<int> combination;
        combineHeler(n, k, 1, combination, result);
        return result;
    }

    void combineHeler(int n, int k, int i, vector<int> combination, vector<vector<int> > &result) {
        if (combination.size() == k) {
            result.push_back(combination);
            return;
        }
        if (i == n + 1)
        	return;
        combineHeler(n, k, i + 1, combination, result);
        combination.push_back(i);
        combineHeler(n, k, i + 1, combination, result);
    }
};

int main() {
    return 0;
}




class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> sub;
        vector<vector<int> > res;
        comb(n,1,k,sub,res);
        return res;
    }
    
    bool comb(int n, int start, int k, vector<int> &sub, vector<vector<int> > &res){
        if(k==0)
            return true;
            
        for(int i=start; i<=n; i++){
            sub.push_back(i);
            if(comb(n,i+1,k-1,sub,res)){
                res.push_back(sub);
                sub.pop_back();
            }else{
                sub.pop_back();
            }  
        }
        return false;
    }
};
