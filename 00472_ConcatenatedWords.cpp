/*
Given a list of words, please write a program that returns all concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
The returned elements order does not matter.
*/

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict;
        sort(words.begin(), words.end(), [](string a, string b) { return a.length() < b.length(); });
        vector<string> res;
        for (auto &w : words) {
            if (w.length() == 0)
                continue;
            if (wordBreak(w, dict))
                res.push_back(w);
            dict.insert(w);
        }
        return res;
    }
private:
    bool wordBreak(string &w, unordered_set<string> &dict) {
        int N = w.length();
        vector<bool> dp(N + 1, false);//at length i, word break is true/false
        dp[0] = true;
        for (int i = 0; i < N; i++){
            for (int j = i; j >= 0; j--){
                if (dict.find(w.substr(j, i - j + 1)) != dict.end() && dp[j]) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};
