/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:

"1 + 1" = 2
" 6-4 / 2 " = 4
"2*(5+5*2)/3+(6/2+8)" = 21
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
 

Note: Do not use the eval built-in library function.
*/

class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return calculateHelper(s, i);
    }
private:
    int calculateHelper(string &s, int &i) {
        vector<int> v;
        char op = '+';
        while (i < s.length() && op != ')') {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            int num = 0;
            if (s[i] == '(') {
                num = calculateHelper(s, ++i);
            } else {
                if (isdigit(s[i]))
                    num = parseNum(s, i);
            }
            switch(op) {
                case '+' :
                    v.push_back(num);
                    break;
                case '-' :
                    v.push_back(-num);
                    break;
                case '*' :
                    v.back() *= num;
                    break;
                case '/' :
                    v.back() /= num;
                    break;
            }            
            if (i < s.length())
                op = s[i];
            i++;
        }
        int res = 0;
        for (int num : v)
            res += num;
        return res;
    }
    
    int parseNum(string &s, int &i) {
        int n = 0;
        while(i < s.length() && isdigit(s[i]))
            n = s[i++] - '0' + 10 * n;
        return n;
    }
};
