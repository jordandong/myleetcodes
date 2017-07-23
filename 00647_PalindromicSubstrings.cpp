/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.
*/

class Solution {
public:
    int countSubstrings(string s) {
        int res = s.length();
        for (int l = 2; l <= s.length(); l++) {
            for (int i = 0; i <= s.length() - l; i++) {
                if (check(s.substr(i, l)))
                    res++;
            }    
        }
        return res;
    }
    
    bool check(string a) {
        int i = 0, j = a.length() - 1;
        while (i <= j) {
            if (a[i++] != a[j--])
                return false;
        }
        return true;
    }
};
