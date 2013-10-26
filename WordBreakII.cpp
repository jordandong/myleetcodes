/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int size = s.size();
        vector<string> set;
        bool dp[size+1];
        for(int i =0; i<=size; i++)
            dp[i]=false;
        dp[0] = true;
        
        for(int j=0; j<size; j++){
            for(int k=j; k>=0; k--){
                if(dict.find(s.substr(k,j-k+1))!=dict.end()&&dp[k]){
                    dp[j+1] = true;
                }
            }
        }
        
        if(dp[size])
            get_path(s,dict,"", set, 0, dp);
        return set;
    }
    
    bool get_path(string &s, unordered_set<string> &dict, string tmp, vector<string> &set, int last, bool *dp){
        if(last==s.size()){
            set.push_back(tmp);
            return true;
        }
        
        for(int i=last; i<s.size(); i++){
            if(!dp[i+1])
                continue;
            string sub = s.substr(last,i-last+1);
            if(dict.find(sub)!=dict.end()){
                string sub1 = tmp + (tmp.size()?(" "+ sub):sub);
                get_path(s,dict,sub1, set, i+1, dp);
            }
        }
        return false;
    }
};
