/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it.
Find and return the shortest palindrome you can find by performing this transformation.

For example:
Given "aacecaaa", return "aaacecaaa".
Given "abcd", return "dcbabcd".
*/

class Solution {
public:
    string shortestPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (j >= 0) {
            if (s[i] == s[j])
                i++;
            j--;
        }
        // aacecaaa
        //aaacecaa
        if (i == s.length())
            return s;

        string suffix = s.substr(i);
        string r_suffix = suffix;
        reverse(r_suffix.begin(), r_suffix.end());
        return r_suffix + shortestPalindrome(s.substr(0, i)) + suffix;
    }
};

//KMP next array, indicated return to where to start if no matching
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.length() == 0)
            return "";
        
        string rs = s;
        reverse(rs.begin(), rs.end());
        
        string ns = s + rs + ".";
        int next[ns.length()];
        int j = 0;
        int k = -1;
        next[0] = k;
        while (j < ns.length() - 1) {
            if(k == -1 || ns[j] == ns [k]){
                next[++j] = ++k;
            }else{
                k = next[k];
            }
        }
        return rs.substr(0, rs.length() - next[ns.length() - 1]) + s;
    }
};
