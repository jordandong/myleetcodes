/*
Given a string containing only three types of characters: '(', ')' and '*',
write a function to check whether this string is valid. We define the validity of a string by these rules:
1. Any left parenthesis '(' must have a corresponding right parenthesis ')'.
2. Any right parenthesis ')' must have a corresponding left parenthesis '('.
3. Left parenthesis '(' must go before the corresponding right parenthesis ')'.
4. '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
5. An empty string is also valid.

Example 1:
Input: "()"
Output: True

Example 2:
Input: "(*)"
Output: True

Example 3:
Input: "(*))"
Output: True

Note:
1. The string size will be in the range [1, 100].
*/

class Solution {
public:
    bool checkValidString(string s) {
        int mi = 0, mx = 0; //record min / max left '(' unmatched
        for (auto c : s) {
            if (c == '(')
                mi += 1;
            else
                mi -= 1; //* as ')'
            
            if (c != ')')
                mx += 1; //* as '('
            else
                mx -= 1;
        
            if (mx < 0)
                return false;
            mi = max(mi, 0);
        }
        return mi == 0;
    }
};

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size(), nl = 0, nr = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '*')
                ++nl; // '*' as '('
            if (s[i] == ')') {
                if (nl == 0) {
                    return false;
                } else {
                    --nl;
                }
            }
            
            if (s[n - i - 1] == ')' || s[n - i - 1] == '*')
                ++nr; // '*' as ')'
            if (s[n - i - 1] == '(') {
                if (nr == 0) {
                    return false;
                } else {
                    --nr;
                }
            }
        }
        //matching all '(' or ')', '*' may be left
        return true;
    }
};
