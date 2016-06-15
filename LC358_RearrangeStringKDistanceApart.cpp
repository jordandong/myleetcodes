/*
Given a non-empty string str and an integer k, rearrange the string such that the same characters are at least distance k from each other.
All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Example 1:
str = "aabbcc", k = 3
Result: "abcabc"
The same letters are at least distance 3 from each other.

Example 2:
str = "aaabc", k = 3 
Answer: ""
It is not possible to rearrange the string.

Example 3:
str = "aaadbbcc", k = 2
Answer: "abacabcd"
Another possible answer is: "abcabcda"
The same letters are at least distance 2 from each other.

Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <queue>
using namespace std;

string rearrangeString(string s, int k) {
    string res = s;
    priority_queue<pair<int, char>, vector<pair<int, char>>> q;
    char mp[256] = {0};
    for(int i = 0; i < res.length(); i++) {
        mp[res[i]]++;
    }
    for(int i = 0; i < 256; i++) {
        if (mp[i] > 0)
            q.push({mp[i], i});
    }

    if (k*(q.top().first - 1) + 1 > res.length())
        return "";

    int start = 0, round = 0;
    while (!q.empty()) {
        auto e = q.top();
        q.pop();
        while (e.first > 0) {
            if (start + k*round >= res.length()) {
                start++;
                round = 0;
            }
            res[start + round*k] = e.second;
            e.first--;
            round++;
        }
    }
    return res;
}

class Solution {
public:
    string rearrangeString(string str, int k) {
        if (k == 0)
            return str;
        string res;
        int len = (int)str.size();
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> q;
        for (auto a : str)
             ++m[a];
        for (auto it = m.begin(); it != m.end(); ++it) {
            q.push({it->second, it->first});
        }
        while (!q.empty()) {
            vector<pair<int, int>> v;
            int cnt = min(k, len);
            for (int i = 0; i < cnt; ++i) {
                if (q.empty())
                    return "";
                auto t = q.top();
                q.pop();
                res.push_back(t.second);
                if (--t.first > 0)
                    v.push_back(t);
                --len;
            }
            for (auto a : v)
                q.push(a);
        }
        return res;
    }
};

int main() {
    Solution sol;
    for (int i = 1; i < 8; i++) {
        cout<<rearrangeString("aaaaabbbbccccdddd", i)<<endl;
        cout<<sol.rearrangeString("aaaaabbbbccccdddd", i)<<endl;
    }
    return 0;
}

aaaaaddddccccbbbb
adcbadcbadcbadcba
acacacacabdbdbdbd
adcbadcbadcbadcba
adcadbadbacbacbdc
adcbadcbadcbadcba
adcbadcbadcbadcba
adcbadcbadcbadcba
""
""
""
""
""
""
