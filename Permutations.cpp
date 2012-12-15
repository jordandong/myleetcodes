//============================================================================
// Given a collection of numbers, return all possible permutations.
//
// For example,
// [1,2,3] have the following permutations:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
//============================================================================


class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
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
                swap(num[begin], num[i]);
                perm(res, begin+1, num);
                swap(num[begin], num[i]);
            }
        }
    }
};




#include <vector>
using namespace std;

class Solution {
public:
    void permuteHelper(vector<int> num, int i, vector<vector<int> > &result) {
        if (i == num.size())
			result.push_back(num);
        else {
            for (int j = i; j < num.size(); j++) {
                swap(num[i], num[j]);
                permuteHelper(num, i + 1, result);
                swap(num[i], num[j]);
            }
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        permuteHelper(num, 0, result);
        return result;
    }
};

int main() {
	return 0;
}
