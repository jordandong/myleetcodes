/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/

class Solution {
public:
    void reverseWords(string &s) {
        int len = s.length();
        stack<char> stk;
        string res;
        
        for(int i = len-1; i>=0; i--){
            if(s[i]==' '){
                if(stk.empty()){
                    continue;
                }else{
                    while(!stk.empty()){
                        res.push_back(stk.top());
                        stk.pop();
                    }
                   res.push_back(' ');
                }
            }else{
                stk.push(s[i]);
            }
        }
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        if(res.back()==' ')
            res.pop_back();
        s = res;
    }
};



class Solution {
public:
    void reverseWords(string &s) {
        int first = -1;
        int second = -1;
        string r="";
        for(int i=0; i<s.length(); i++){
            if(s[i]==' '){
                if(first==-1 || second ==-1){
                    continue;
                }else{
                    r = " " + r;
                    r = s.substr(first, second-first+1) + r;
                    first=-1;
                    second =-1;
                }
            }else{
                if(first==-1){
                    first=i;
                    second=i;
                }else{
                    second = i;
                }
            }
                
        }
        
        if(first!=-1 && second !=-1){
            r = " " + r;
            r = s.substr(first, second-first+1) + r;
            first=-1;
            second =-1;
        }
        int size = r.length();
        if(size >0 && r[size-1]==' ')
            s = r.substr(0, size-1);
        else
            s = r;
    }
};
