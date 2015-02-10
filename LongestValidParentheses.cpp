/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

Hide Tags Dynamic Programming String
*/

//T : O(n), S : O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int size = s.length();
        int maxL = 0;
        for(int i = 0; i < size; i++){
            if(s[i]=='('){
                stk.push(i);
            }else{
                if(!stk.empty() && s[stk.top()]=='('){
                    stk.pop();
                    maxL = max(maxL, i - (stk.empty() ? -1:stk.top() ) );
                }else{
                    stk.push(i);
                }
            }
        }
        return maxL;
    }
};

//T : O(n) S : O(1)
class Solution {
public:
    int longestValidParentheses(string s) {
        int N=s.size();
        if (N < 2)
            return 0;
        int res = 0;
        int k = 0, l = 0;
        for(int i = 0; i < N; i++){
            if(s[i] == '('){
                k++;
                l++;
            }else{
                k--;
                l++;
            }
            if(k == 0 && l > res) // match
                res = l;
            else if(k < 0){//')' is in front, reset
                k = 0;
                l = 0;
            }
        }
        //cannot figure out like "(((((())"
        //so need to start from the end again
        k = 0;
        l = 0;
        for(int i = N-1; i > 0; i--){
            if (s[i] == ')'){
                k++;
                l++;
            }else{
                k--;
                l++;
            }
            if(k == 0 && l > res)
                res = l;
            else if (k < 0){
                k = 0;
                l = 0;
            }
        }
        return res;
    }
};
