/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

For example,
If S = [1,2,2], a solution is:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

Hide Tags Array Backtracking
*/

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        int sz = S.size();
        vector<vector<int> > res;
        int last_sz = 0;
        int cur_sz = 0;
        
        res.push_back(vector<int>());
        sort(S.begin(), S.end());

        for(int i = 0; i < sz ; i++){
            cur_sz = res.size();
            int start = 0;
            if(i > 0 && S[i] == S[i-1]){
                start = last_sz; //Avoild Dup, only apply dup element to the new added solutions
            }
            last_sz = cur_sz;
            for(; start < cur_sz; start++){//add new elements based on all emelemts OR based on last sz
                vector<int> tmp = res[start];
                tmp.push_back(S[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
