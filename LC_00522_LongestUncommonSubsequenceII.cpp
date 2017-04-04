/*
Given a list of strings, you need to find the longest uncommon subsequence among them.
The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements.
Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence.
If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc", "eae"
Output: 3

Note:
1. All the given strings' lengths will not exceed 10.
2. The length of the given list will be in the range of [2, 50].

Hide Tags String
*/

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(),
             [](string a, string b) {
                return a.size() > b.size() || (a.size() == b.size() && a < b);
             });
        unordered_map<string, int> mp;
        for (int i = 0; i < strs.size(); ++i)
            mp[strs[i]]++;
        for (int i = 0; i < strs.size(); ++i) {
            if (mp[strs[i]] == 1) { //if dup, not candidate
                int j = 0;
                while (j < i) {
                    if (isSub(strs[i], strs[j]))
                        break;
                    j++;
                }
                if (j == i)
                    return strs[i].size();
            }
        }
        return -1;
    }

    bool isSub(string &a, string &b){
        if (a.size() > b.size())
            return false;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()){
            if (a[i] == b[j++])
                i++;
        }
        return i == a.size();
    }
};
