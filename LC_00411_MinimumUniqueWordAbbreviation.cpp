/*
A string such as "word" contains the following abbreviations:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Given a target string and a set of strings in a dictionary, find an abbreviation of this target string with the smallest possible length such that it does not conflict with abbreviations of the strings in the dictionary.

Each number or letter in the abbreviation is considered length = 1. For example, the abbreviation "a32bc" has length = 4.

Note:
In the case of multiple answers as shown in the second example below, you may return any one of them.
Assume length of target string = m, and dictionary size = n. You may assume that m ≤ 21, n ≤ 1000, and log2(n) + m ≤ 20.

Examples:
"apple", ["blade"] -> "a4" (because "5" or "4e" conflicts with "blade")
"apple", ["plain", "amber", "blade"] -> "1p3" (other valid answers include "ap3", "a3e", "2p2", "3le", "3l1").
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        int len = target.size();
        if (len == 0)
            return "";
        vector<string> dict;
        for (string &s : dictionary) {
            if (s.size() == len) {
                dict.push_back(s);
            }
        }
        if (dict.size() == 0) 
            return to_string(len);
        string res = target;
        dfs("", 0, target, 0, dict, res, len);
        return res;
    }

    void dfs(string cur, int cur_len, string &target, int pos, vector<string>&dict, string &res, int &min_len) {
        if (pos >= (int)target.size()) {
            if (cur_len < min_len) { //prune
                bool found = true;
                for (string &s : dict) {
                    if (validWordAbbreviation(s, cur)) {
                        found = false;
                        break;
                    }
                }
                if (found){
                    res = cur;
                    min_len = cur_len;
                }
            }
            return;
        }

        if (min_len == cur_len)
            return;   //prune

        if (cur.empty() || !isdigit(cur.back())) {
            for(int i = target.size() - 1; i >= pos; i--) {
                 string add = to_string(i - pos + 1);
                 dfs(cur + add, cur_len + 1, target, i + 1, dict, res, min_len);
            }
        }
        dfs(cur + target[pos], cur_len + 1, target, pos + 1, dict, res, min_len);
    }

    bool validWordAbbreviation(string &word, string &abbr) {
        int i = 0, digit = 0;
        for (const auto &c : abbr) {
            if (isdigit(c)) {
                if (digit == 0 && c == '0') {
                    return false;
                } 
                digit *= 10;
                digit += c - '0';
            } else {
                if (digit) {
                    i += digit;
                    digit = 0;
                }
                if (i >= word.length() || word[i++] != c) {
                    return false;
                }
            }
        }
        if (digit) {
            i += digit;
        }
        return i == word.length();
    }
};

int main() {
    vector<string> dict = {"plain"};//, "amber", "blade"};
    Solution s;
    cout  << s.minAbbreviation("apple", dict)<<endl;
    return 0;
}
