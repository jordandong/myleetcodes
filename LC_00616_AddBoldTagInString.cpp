/*
Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict.
If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag.
Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.

Example 1:
Input: 
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"

Example 2:
Input: 
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"

Note:
1. The given dict won't contain duplicates, and its length won't exceed 100.
2. All the strings in input have length in range [1, 1000].

Hide Tags String
*/

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int N = s.length();
        bool bold[N] = {false};
        for (auto w : dict) {
            int idx = 0;
            while ((idx = s.find(w, idx)) >= 0) {
                memset(bold + idx, true, w.length());
                idx++;
            }
        }
        string res = "";
        for (int i = 0; i < N; i++) {
            if (bold[i] && (i == 0 || !bold[i - 1]))
                res += "<b>";
            res.push_back(s[i]);
            if (bold[i] && (i == N - 1 || !bold[i + 1]))
                res += "</b>";
        }
        return res;
    }
};

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int N = s.length();
        int start = -1, end = -1;
        string ans = "";
        for (int i = 0; i < N; i++) {
            int l = 0;
            for (auto w : dict) {
                if (s.find(w, i) == i)
                    l = (l >= w.length() ? l : w.length());
            }
            if (l) {
                if (start == -1)
                    start = i;
                end = max(end, l + i);
                continue;
            }
            if (end > -1 && i >= end) {
                ans += ("<b>" + s.substr(start, end - start) + "</b>");
                start = -1;
                end = -1;
            }
            if (start == -1)
                ans.push_back(s[i]);
        }
        if (start > -1)
            ans += ("<b>" + s.substr(start, end - start) + "</b>");
        return ans;
    }
};
