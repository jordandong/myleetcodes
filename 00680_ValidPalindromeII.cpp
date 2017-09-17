/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/

class Solution {
public:
    bool validPalindrome(string s) {
        int lo = 0, hi = s.length() - 1;
        bool mod = false;
        while (lo <= hi) {
            if (s[lo] == s[hi]) {
                lo++;
                hi--;
            } else {
                if (mod)
                    return false;

                if (s[lo] == s[hi - 1] && s[lo + 1] == s[hi])
                    return check(s.substr(lo, hi - lo)) || check(s.substr(lo + 1, hi - lo));

                if (s[lo] == s[hi - 1]) {
                    hi--;
                } else if (s[lo + 1] == s[hi]) {
                    lo++;
                }
                
                mod = true;
            }
        }
        return true;
    }
    
    bool check(string s) {
        int lo = 0, hi = s.length() - 1;
        while (lo <= hi) {
            if (s[lo] == s[hi]) {
                lo++;
                hi--;
            } else {
                return false;
            }
        }
        return true;
    }
};
