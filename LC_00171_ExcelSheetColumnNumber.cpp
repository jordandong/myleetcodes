/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Tags Math
*/

class Solution {
public:
    int titleToNumber(string s) {
        int sz = s.length();
        int res = 0;
        for(int i = sz - 1; i >= 0; i--){
            res += ((s[i] - 'A') + 1)*(pow(26, sz - 1 - i));
        }
        return res;
    }
};
