/*
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.
*/

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        for (string &w : d) {
            if (w.length() >= ans.length() && canFind(s, w)) {
                if (w.length() > ans.length() || w < ans)
                    ans = w;
            }
        }
        return ans;
    }
private:
    bool canFind(string &s, string &w) {
        for (int j = 0, i = 0; j < w.length(); j++,i++) {
            while (i < s.length() && s[i] != w[j])
                i++;
            if (i == s.length())
                return false;
        }
        return true;
    }
};
