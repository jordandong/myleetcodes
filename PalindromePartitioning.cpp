/**
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
**/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> curr;
        vector<vector<string> > res;
        if(s.length())
            partition_one(s, curr, res);
        return res;
       
    }
    
    void partition_one(string s, vector<string> &curr, vector<vector<string> > &res){
        int len = s.length();
        if (len==0){
            res.push_back(curr);
            return;
        }
        for(int i=1;i<=len;i++){
            string tmp = s.substr(0,i);
            if(judge(tmp)){
                curr.push_back(tmp);
                partition_one(s.substr(i), curr, res);
                curr.pop_back();
            }
        }
    }
    
    bool judge(string s){
        int j = s.length()-1;
        int i=0;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};