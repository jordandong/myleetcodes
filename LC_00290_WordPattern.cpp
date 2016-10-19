/*
Given a pattern and a string str, find if str follows the same pattern.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.

Notes:
1. Both pattern and str contains only lowercase alphabetical letters.
2. Both pattern and str do not have leading or trailing spaces.
3. Each word in str is separated by a single space.
4. Each letter in pattern must map to a word with length that is at least 1.

Credits:
Special thanks to @minglotus6 for adding this problem and creating all test cases.

Hide Tags Hash Table
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map <char, string> p2s;
        unordered_map <string, char> s2p;
        int Lp = pattern.length();
        int Ls = str.length();
        int i = 0, j = 0, p = 0;
        while (i < Ls && p < Lp) {
            while (j < Ls && str[j] != ' ')
                j++;
            string wd = str.substr(i, j - i);
            if (p2s.find(pattern[p]) == p2s.end() && s2p.find(wd) == s2p.end()) {
                p2s[pattern[p]] = wd;
                s2p[wd] = pattern[p];
            } else if (p2s[pattern[p]] != wd) {
                return false;
            }
            i = ++j;
            p++;
        }
        return (p == Lp) && (i == Ls + 1); 
    }
};
