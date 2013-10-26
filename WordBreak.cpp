/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int size = s.size();
        bool dp[size+1];
        for(int i =0; i<=size; i++)
            dp[i]=false;
        dp[0] = true;
        
        for(int j=0; j<size; j++){
            for(int k=j; k>=0; k--){
                if(dict.find(s.substr(k,j-k+1))!=dict.end()&&dp[k]){
                    dp[j+1] = true;
                    break;
                }
            }
        }
        return dp[size];
    }
};
