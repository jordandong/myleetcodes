/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
"((()))", "(()())", "(())()", "()(())", "()()()"

Hide Tags Backtracking String
*/

//optimize the space
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string sol;
        vector<string> res;
        gpHelper(n, n, sol, res);
        return res;
    }
    
    void gpHelper(int l, int r, string &sol, vector<string> &res){
        if(l==0 && r==0){
            res.push_back(sol);
            return;
        }
        if(l>0){
            sol.push_back('(');
            gpHelper(l-1, r, sol, res);
            sol.pop_back();
        }
        if(r>l){
            sol.push_back(')');
            gpHelper(l, r-1, sol, res);
            sol.pop_back();
        }
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisHeler(n, n, "", result);
        return result;
    };

    void generateParenthesisHeler(int l, int r, string s, vector<string> &result) {
        if (l == 0 && r == 0)
            result.push_back(s);
        if (l > 0)
            generateParenthesisHeler(l - 1, r, s + '(', result);
        if (r > l)
            generateParenthesisHeler(l, r - 1, s + ')', result);
    };
};
