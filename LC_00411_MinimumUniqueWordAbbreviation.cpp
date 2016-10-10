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
#include <string>
#include <vector>
#include <algorithm>    // std::all_of
#include <array>        // std::array
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

class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        vector<int> diffs;
        dictionary_to_diffs(target, dictionary, &diffs);

        if (diffs.empty()) {
            return to_string(target.length());
        }

        int bits = (1 << target.length()) - 1;
        for (int i = 0; i < (1 << target.length()); ++i) {
            if (all_of(diffs.begin(), diffs.end(), [&i](int d) { return d & i; } )) {
                if (bits_len(target, i) > bits_len(target, bits)) {
                    bits = i;
                }
            }
        }

        return bits_to_abbr(target, bits);
    }

private:
    void dictionary_to_diffs(const string& target, const vector<string>& dictionary,
                             vector<int> *diffs) {

        for (const auto& word : dictionary) {
            if (word.length() != target.length()) {
                continue;
            }

            int bits = 0;
            for (int i = 0; i < word.length(); ++i) {
                if (target[i] != word[i]) {
                    bits |= 1 << i;
                }
            }
            diffs->emplace_back(bits);
        }
    }

    int bits_len(const string& target, int bits) {
        int sum = 0;

        for (int i = 0; i < target.length() - 1; ++i) {
            if (((bits >> i) & 3) == 0) {
                ++sum;
            }
        }

        return sum;
    }

    string bits_to_abbr(const string& target, int bits) {
        string abbr;

        int pre = 0;
        for (int i = 0, prev = 0; i < target.length(); ++i, bits >>= 1) {
            if (bits & 1) {
                if (i - pre > 0) {
                    abbr += to_string(i - pre);
                }
                pre = i + 1;
                abbr.push_back(target[i]);
            } else if (i == target.length() - 1) {
                abbr += to_string(i - pre + 1);
            }
        }

        return abbr;
    }
};

int main() {
    vector<string> dict = {"plain", "amber", "blade"};
    Solution s;
    cout  << s.minAbbreviation("apple", dict)<<endl;
    return 0;	
}
