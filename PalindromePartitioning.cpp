/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
  
Hide Tags Backtracking
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> sol;
        vector<vector<string> > res;
        if(s.length())
            partitionHelper(s, 0, sol, res);
        return res;
       
    }
    
    void partitionHelper(string &s, int start, vector<string> &sol, vector<vector<string> > &res){
        if(start == s.length()){
            res.push_back(sol);
            return;
        }

        for(int i = 1; i <= s.length() - start; i++){
            string tmp = s.substr(start, i);
            if(isPalindrome(tmp)){
                sol.push_back(tmp);
                partitionHelper(s, start + i, sol, res);
                sol.pop_back();
            }
        }
    }
    
    bool isPalindrome(string &s){
        int j = s.length() - 1;
        int i = 0;
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
