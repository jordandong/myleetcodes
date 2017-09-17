/*
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
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
The string size will be in the range [1, 100].
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