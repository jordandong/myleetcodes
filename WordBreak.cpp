/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

Hide Tags Dynamic Programming
*/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int sz = s.length();
        bool dp[sz + 1];//at length i, word break is true/false
        memset(dp, 0, (sz + 1)*sizeof(bool));
        dp[0] = true;
        for(int i = 0; i < sz; i++){
            for(int j = i; j >= 0; j--){
                if(dict.find(s.substr(j, i - j + 1)) != dict.end() && dp[j]){
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[sz];
    }
};
