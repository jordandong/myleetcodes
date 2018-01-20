/*
Given a set of keywords words and a string S, make all appearances of all keywords in S bold. Any letters between <b> and </b> tags become bold.

The returned string should use the least number of tags possible, and of course the tags should form a valid combination.

For example, given that words = ["ab", "bc"] and S = "aabcd", we should return "a<b>abc</b>d".
Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.

Note:
1. words has length in range [0, 50].
2. words[i] has length in range [1, 10].
3. S has length in range [0, 500].
4. All characters in words[i] and S are lowercase letters.
*/

class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int N = S.length();
        bool bold[N] = {false};
        for (auto w : words) {
            int idx = 0;
            while ((idx = S.find(w, idx)) >= 0) {
                memset(bold + idx, true, w.length());
                idx++;
            }
        }
        string res = "";
        for (int i = 0; i < N; i++) {
            if (bold[i] && (i == 0 || !bold[i - 1]))
                res += "<b>";
            res.push_back(S[i]);
            if (bold[i] && (i == N - 1 || !bold[i + 1]))
                res += "</b>";
        }
        return res;
    }
};

class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int N = S.length();
        int start = -1, end = -1;
        string ans = "";
        for (int i = 0; i < N; i++) {
            int l = 0;
            for (auto w : words) {
                if (S.find(w, i) == i)
                    l = (l >= w.length() ? l : w.length());
            }
            if (l) {
                if (start == -1)
                    start = i;
                end = max(end, l + i);
                continue;
            }
            if (end > -1 && i >= end) {
                ans += ("<b>" + S.substr(start, end - start) + "</b>");
                start = -1;
                end = -1;
            }
            if (start == -1)
                ans.push_back(S[i]);
        }
        if (start > -1)
            ans += ("<b>" + S.substr(start, end - start) + "</b>");
        return ans;
    }
};
