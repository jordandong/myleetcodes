//============================================================================
// Permutations II
// Given a collection of numbers that might contain duplicates, return all
// possible unique permutations.
//
// For example,
// [1,1,2] have the following unique permutations:
// [1,1,2], [1,2,1], and [2,1,1].
//============================================================================


class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        perm(res, 0, num);
        return res;
        
    }
    
    void perm(vector<vector<int> > &res, int begin, vector<int> &num){
        if(begin==num.size()){
            res.push_back(num);
        }
        else{
            for(int i=begin; i<num.size(); i++){
                if(IsSwap(begin, i, num)){
                    swap(num[begin], num[i]);
                    perm(res, begin+1, num);
                    swap(num[begin], num[i]);
                }
            }
        }
    }

    bool IsSwap(int begin, int curr, vector<int> & num){
        while(begin<curr){
            if(num[begin]==num[curr])
                return false;
            begin++;
        }
        return true;
    } 
};



#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    void reverse(vector<int> &num, int i, int j) {
        while(i<j)
			swap(num[i++], num[j--]);
    };

    void nextPermutation(vector<int> &num) {
        int N=num.size();
        if(N<2)
			return;
        int i=N-2;
        while(i>=0 && num[i]>=num[i+1])
			i--;
        if (i == -1) {
            reverse(num, 0, N - 1);
            return;
        }
        int j=N-1;
        while(j>i && num[j]<=num[i])
			j--;
        swap(num[i], num[j]);
        reverse(num, i+1, N-1);
    };

    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        do {
            result.push_back(num);
            nextPermutation(num);
        } while (!equal(result[0].begin(), result[0].end(), num.begin()));
        return result;
    }
};

int main() {
    return 0;
}
