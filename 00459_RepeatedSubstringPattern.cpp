/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int N = str.length();
        for (int i = 1; i < N / 2 + 1; i++) {
            if (N % i)
                continue;
            string sub = str.substr(0, i);
            int idx = 0;
            for (idx = 0; idx < N; idx += i) {
                if (sub != str.substr(idx, i))
                    break;
            }
            if (idx == N)
                return true;
        }
        return false;
    }
};

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int N = str.length();
        if ( N < 2)
            return false;
        for (int repeat = 2; repeat <= N; repeat++) {
            if (N % repeat)
                continue;
            if (checkRepeat(str, repeat))
                return true;
        }
        return false;
    }
    
    bool checkRepeat(string &str, int repeat) {
        int N = str.length();
        string sub = str.substr(0, N / repeat);
        for (int i = 0; i < N; i++){
            if (str[i] != sub[i % (N / repeat)])
                return false;
        }
        return true;
    }
};
