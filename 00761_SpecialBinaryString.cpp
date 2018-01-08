/*
Special binary strings are binary strings with the following two properties:

The number of 0's is equal to the number of 1's.
Every prefix of the binary string has at least as many 1's as 0's.
Given a special string S, a move consists of choosing two consecutive, non-empty, special substrings of S, and swapping them. (Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.)

At the end of any number of moves, what is the lexicographically largest resulting string possible?

Example 1:
Input: S = "11011000"
Output: "11100100"
Explanation:
The strings "10" [occuring at S[1]] and "1100" [at S[3]] are swapped.
This is the lexicographically largest string possible after some number of swaps.
Note:

S has length at most 50.
S is guaranteed to be a special binary string as defined above.
*/


//1 + S + 0 ,recursion on middle S part
class Solution {
public:
    string makeLargestSpecial(string S) {
        int count = 0, i = 0;
        vector<string> res;
        for (int j = 0; j < S.size(); ++j) {
            if (S[j] == '1')
                count++;
            else
                count--;
            if (count == 0) {
                res.push_back('1' + makeLargestSpecial(S.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }
        sort(res.begin(), res.end(), greater<string>());
        string ans = "";
        for (auto &s : res)
            ans += s;
        return ans;
    }
};

class Solution {
public:
    string makeLargestSpecial(string S) {
        int i = 0;
        return makeLargestSpecialHelper(S, i);
    }

private:
    string makeLargestSpecialHelper(string &S, int &i) {
        string res;
        vector<string> toks;
        while (i < S.size() && res.empty()) {
            if (S[i++] == '1')
                toks.push_back(makeLargestSpecialHelper(S, i));
            else
                res += "1";
        }
        bool prefix = res.size();
        sort(toks.begin(), toks.end());
        for (auto it = toks.rbegin(); it != toks.rend(); it++)
            res += *it;
        if (prefix)
            res += '0';
        return res;
    }
};
