/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!tokens.size())
            return 0;
        stack<int> s;
        for(auto &t : tokens){
            if(t.length()==1 && (t[0]<'0' || t[0]>'9')){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if(t[0]=='+')
                    s.push(b+a);
                if(t[0]=='-')
                    s.push(b-a);
                if(t[0]=='*')
                    s.push(b*a);
                if(t[0]=='/')
                    s.push(b/a);               
            }else{
                int num = 0;
                int sign = 1;
                for(auto& c : t){
                    if(c=='-')
                        sign = -1;
                    else
                        num=10*num + (c-'0');
                }
                s.push(sign*num);
            }
        }
        return s.top();
    }
};
