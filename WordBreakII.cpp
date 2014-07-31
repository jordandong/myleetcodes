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


//recursion
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> rtn;
        string cur="";
        vector<bool> dp(s.length(), true); //dp[i] means start form index i, there is a solution
        wBHelper(s, 0, cur, dict, rtn, dp);
        return rtn;
    }
    void wBHelper(string &s, int start, string cur, unordered_set<string> &dict, vector<string>& rtn, vector<bool> &dp){
        if(start==s.length()){
            if(!cur.empty())
                cur.pop_back();//pop the last space
            rtn.push_back(cur);
            return;
        }
        
        for(int end=start; end<s.length(); end++){
            string sub = s.substr(start, end-start+1);
            if(dict.find(sub)==dict.end())
                continue;
            if(dp[end+1]){ //if no solution, we continue
                int sol_num = rtn.size(); //sol before go further
                wBHelper(s, end+1, cur+sub+" ", dict, rtn, dp);
                dp[end+1] = sol_num!=rtn.size(); //sol after go futher, set false if no sol increasing
            }
        }
    }
};
