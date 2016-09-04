/*
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

Example 1:
Input:
s = "aaabb", k = 3
Output:
3
The longest substring is "aaa", as 'a' is repeated 3 times.

Example 2:
Input:
s = "ababbc", k = 2
Output:
5
The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstringHelper(s, k, 0, s.length());
    }
private:
    int longestSubstringHelper(string &s, int k, int start, int end) {
        vector<int> mp(26, 0);
        for (int i = start; i < end; i++)
            mp[s[i] - 'a']++;
        int res = 0;
        for(int i = start; i < end; i++) {
            while (i < end && mp[s[i] - 'a'] < k)
                ++i;
            if (i == end)
                break;
            int j = i;
            while (j < end && mp[s[j] - 'a'] >= k)
                ++j;
            if (i == start && j == end)
                return end - start; 
            res = max(res, longestSubstringHelper(s, k, i, j));
            i = j;
        }
        return res;
    }
};

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s == "")
            return 0;
        vector<int> mp(26, 0);
        for (auto c : s)
            mp[c - 'a']++;

        vector<string> next = {""};
        bool k_met = true;
        for (auto c : s) {
            if(mp[c - 'a'] < k) {
                if (next.back() != "")
                    next.push_back("");
                k_met = false;
            } else {
                next.back() += c;
            }
        }
        if (k_met)
            return next.back().length();
        
        int res = 0;
        for(auto ss : next) {
            res = max(longestSubstring(ss, k), res);
        }
        return res;
    }
};
