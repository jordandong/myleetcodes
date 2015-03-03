/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases.

Hide Tags Math
*/
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n){
            int r = (n - 1)%26;
            string s = "";
            s.push_back(r + 'A');
            res = s + res;
            n = (n - 1)/26;
        }
        return res;
    }
};
