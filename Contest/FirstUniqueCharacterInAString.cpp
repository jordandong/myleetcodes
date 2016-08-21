/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> map(26, 0);
        for (auto c : s)
            map[c - 'a']++;
        for (int i = 0; i < s.length(); i++)
            if (1 == map[s[i] - 'a'])
                return i;
        return -1;
    }
};
