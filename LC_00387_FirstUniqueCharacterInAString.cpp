/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

//Two passes, T : O(N), S : O(1)
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> map(26, 0);
        for (auto c : s)
            map[c - 'a']++;
        for (int i = 0; i < s.length(); i++)
            if (1 == map[s[i] - 'a'])
                return i;
        return -1;
    }
};

// One pass, T : O(N), S :O(N) 
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> map(256, 0);
        queue<int> q;
        for (int i = 0; i < s.length(); i++) {
            if (++map[s[i]] == 1) {
                q.push(i);
            } else {
                while (!q.empty() && map[s[q.front()]] > 1)
                    q.pop();
            }
        }
        return q.empty() ? -1 : q.front();
        
    }
};

class Solution {
public:
    int firstUniqChar(string s) {
        using IT = list<int>::iterator;
        list<int> candidates;
        unordered_map<char, IT> lookup;
        for (int i = 0; i < s.length(); ++i) {
            const auto c = s[i];
            if (lookup.count(c)) {
                if (lookup[c] != candidates.end()) {
                    candidates.erase(lookup[c]);
                }
                lookup[c] = candidates.end();
            } else {
                lookup[c] = candidates.insert(candidates.end(), i);
            }
        }
        return candidates.empty() ? -1 : candidates.front();
    }
};
