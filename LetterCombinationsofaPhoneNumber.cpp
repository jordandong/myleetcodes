/*
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

Hide Tags Backtracking String
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string pad[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};;
        vector<string> res;
        string sol = "";
        letterCombinationsHelper(pad, digits, 0, sol, res);
        return res;
    }

    void letterCombinationsHelper(string pad[], string& digits, int pos, string &sol, vector<string> &res) {
        if (pos == digits.size()){
            res.push_back(sol);
            return;
        }
        int idx = digits[pos] - '2';
        for (int i = 0; i < pad[idx].size(); i++){
            sol.push_back(pad[idx][i]);
            letterCombinationsHelper(pad, digits, pos + 1, sol, res);
            sol.pop_back();
        }
    }
};
