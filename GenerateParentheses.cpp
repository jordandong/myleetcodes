//============================================================================
// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.
//
// For example, given n = 3, a solution set is:
//
// "((()))", "(()())", "(())()", "()(())", "()()()"
//============================================================================

//optimize the space use
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string cur;
        vector<string> rtn;
        gpHelper(n, n, cur, rtn);
        return rtn;
    }
    
    void gpHelper(int l, int r, string &cur, vector<string> &rtn){
        if(l==0 && r==0){
            rtn.push_back(cur);
            return;
        }
        if(l>0){
            cur.push_back('(');
            gpHelper(l-1, r, cur, rtn);
            cur.pop_back();
        }
        if(r>l){
            cur.push_back(')');
            gpHelper(l, r-1, cur, rtn);
            cur.pop_back();
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
