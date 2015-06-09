/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

Note: Do not use the eval built-in library function.

Hide Tags Stack Math
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> vals;
        stack<char> ops;
        string num = "";

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '+' || s[i] == '-') {
                ops.push(s[i]);
            } else if (s[i] >= '0' && s[i] <= '9') {
                num = s[i] + num;
                if(i == 0 || s[i - 1] < '0' || s[i - 1] > '9') {
                    vals.push(str2num(num)); 
                    num = "";
                }
            } else if (s[i] == '(') {
                while (ops.top() != ')')
                    calculateHelper(vals, ops);
                ops.pop();
            }
        }
        
        while (ops.size())
            calculateHelper(vals, ops);
        return vals.top();
    }

    void calculateHelper (stack<int> &vals, stack<char> &ops) {
        int v1 = vals.top();
        vals.pop();
        int v2 = vals.top();
        vals.pop();
        
        ops.top() == '+' ? vals.push(v1 + v2) : vals.push(v1 - v2);
        ops.pop();
    }
    
    int str2num(string &s) {
        int num = 0;
        for (auto &c : s)
            num = 10 * num + (c - '0');
        return num;
    }
};
