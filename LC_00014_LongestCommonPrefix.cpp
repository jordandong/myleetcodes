/*
Write a function to find the longest common prefix string amongst an array of strings.

Hide Tags String
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int sz = strs.size();
        int k = 0;
        while(++k && sz){
            if(k > strs[0].size()){
                return strs[0];
            }
            char c = strs[0][k-1]; 
            for(int i = 1; i < sz; i++){
                if(k > strs[i].size()){
                    return strs[i];
                }
                if(c != strs[i][k-1])
                    return strs[i].substr(0, k-1);
            }
        }
        return "";
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int N = strs.size();
        if (N == 0)
            return "";
        int l = 0;
        while (l < strs[0].size()) {
            for (int i = 1; i < N; i++) {
                if (l == strs[i].size() || strs[i][l] != strs[0][l])
                    return strs[i].substr(0, l);
            }
            l++;
        }
        return strs[0];
    }
};
