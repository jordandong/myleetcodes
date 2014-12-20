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
*/
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n){
            int r = (n-1)%26;
            string s = "";
            s.push_back(r +'A');
            res= s+res;
            n=(n-1)/26;
        }
        return res;
    }
};
