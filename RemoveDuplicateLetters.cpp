/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"
Given "cbacdcbc"
Return "acdb"

Credits:
Special thanks to @peisi for adding this problem and creating all test cases.
*/


class Solution {
public:
    string removeDuplicateLetters(string s) {
        int counter[26] = { 0 };
        bool used[26] = { 0 };
        string res;
        for (char &c : s)
            counter[c - 'a']++;

        for (char &c : s) {
            --counter[c - 'a'];
            if (used[c - 'a'])
                continue;
            while (res.size() && c < res.back() && counter[res.back() - 'a']) {
                used[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(c);
            used[c - 'a'] = true;
        }
        return res;
    }
};
