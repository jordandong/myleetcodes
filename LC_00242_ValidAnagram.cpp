/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Hide Tags Hash Table Sort
*/

//T : O(m + n + k) S : O(k), k is the letter set size 
class Solution {
public:
    bool isAnagram(string s, string t) {
        int N = 26;
        int mp[N];
        char base = 'a';
        memset(mp, 0, sizeof(mp));
        for (auto &c : s)
            ++mp[c - base];
        for (auto &c : t) {
            if (--mp[c - base] < 0)
                return false;
        }
        
        for (int i = 0; i < N; i++) {
            if(mp[i] != 0)
                return false;
        }
        return true;
    }
};

//T : O(mlogm + nlogn) S : O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
