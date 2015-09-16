/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to add operators +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []

Credits:
Special thanks to @davidtan1890 for adding this problem and creating all test cases.

Hide Tags Divide and Conquer
*/

//DFS
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string sol = "";
        addOperatorsHelper(num, target, 0, 0, 0, sol, res);
        return res;
    }
    
    void addOperatorsHelper(string &num, int target, int pos, long long operand1, long long operand2, string &sol, vector<string> &res) {
        if (pos == num.length()) {
            if (operand1 + operand2 == target)
                res.push_back(sol);
            return;
        }
        
        long long cur_operand = 0;
        string cur_operand_str = "";
        int slen = sol.length();
        for (int i = pos; i < num.length(); i++) {
            cur_operand = cur_operand*10 + (num[i] - '0');
            cur_operand_str += num[i];
            if (cur_operand > INT_MAX)
                return;
                
            if (sol.length() == 0) {
                sol += cur_operand_str;
                addOperatorsHelper(num, target, i + 1, 0, cur_operand, sol, res);
                sol.erase(slen, sol.length() - slen);
            
            } else {
                sol = sol + "+" + cur_operand_str;
                addOperatorsHelper(num, target, i + 1, operand1 + operand2, cur_operand, sol, res);
                sol.erase(slen, sol.length() - slen);
            
                sol = sol + "-" + cur_operand_str;
                addOperatorsHelper(num, target, i + 1, operand1 + operand2, -cur_operand, sol, res);
                sol.erase(slen, sol.length() - slen);
            
                sol = sol + "*" + cur_operand_str;
                addOperatorsHelper(num, target, i + 1, operand1, operand2*cur_operand, sol, res);
                sol.erase(slen, sol.length() - slen);
            }
            if (cur_operand == 0)
                break;
        }
    }
};
