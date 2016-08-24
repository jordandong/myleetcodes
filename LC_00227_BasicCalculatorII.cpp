/*
Implement a basic calculator to evaluate a simple expression string.
The expression string contains only non-negative integers, +, -, *, and / operators. The integer division should truncate toward zero.
You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5

Note: Do not use the eval built-in library function.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Have you met this question in a real interview? Yes  No
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> vals;
        stack<char> ops;
        string num = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*' || s[i] == '/') {
                while (ops.size() && (ops.top() == '*' || ops.top() == '/'))
                    calculateHelper(vals, ops);
                ops.push(s[i]);
            } else if (s[i] == '+' || s[i] == '-') {
                while (ops.size() && (ops.top() == '-' || ops.top() == '*' || ops.top() == '/'))
                    calculateHelper(vals, ops);
                ops.push(s[i]);
            } else if (s[i] >= '0' && s[i] <= '9') {
                num = num + s[i];
                if(i == s.length() - 1 || s[i + 1] < '0' || s[i + 1] > '9') {
                    vals.push(str2num(num)); 
                    num = "";
                }
            }
        }
        
        while (ops.size())
            calculateHelper(vals, ops);
        return vals.top();
    }

    void calculateHelper (stack<int> &vals, stack<char> &ops) {
        char op = ops.top();
        ops.pop();
        int v2 = vals.top();
        vals.pop();
        int v1 = vals.top();
        vals.pop();
        if (op == '+')
            vals.push(v1 + v2);
        else if (op == '-')
            vals.push(v1 - v2);
        else if (op == '*')
            vals.push(v1 * v2);
        else if (op == '/')
            vals.push(v1 / v2);
    }
    
    int str2num(string &s) {
        int num = 0;
        for (auto &c : s)
            num = 10 * num + (c - '0');
        return num;
    }
};
