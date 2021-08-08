/*
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

 

Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false
 

Note:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist only of lowercase letters.
*/

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length())
            return false;
        bool dup = false;
        set<char> exists;
        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                if (idx1 == -1)
                    idx1 = i;
                else if (idx2 == -1)
                    idx2 = i;
                else
                    return false;
            }
            if (exists.find(s[i]) == exists.end()) {
                exists.insert(s[i]);
            } else {
               dup = true; 
            }
        }
        if (idx1 >= 0 && idx2 >= 0) {
            return s[idx1] == goal[idx2] && s[idx2] == goal[idx1];
        } else if (idx1 == -1 && idx2 == -1) {
            return dup;
        }
        return false;
    }
};
