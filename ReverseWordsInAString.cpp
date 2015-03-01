/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.

Hide Tags String
*/

// T : O(3*N) S : O(1)
class Solution {
public:
    void reverseWords(string &s) {
        while(s.length() && s.back() == ' ')
            s.pop_back();
        while(s.length() && s[0] == ' ')
            s.erase(0, 1);
        int i = 0;
        int j = 0;
        while(j <= s.length()){
            if(j == s.length() || s[j] == ' '){
                if(j > 0 && s[j - 1] == ' '){
                    s.erase(j, 1);
                    continue;
                }else{
                    reverse(s.begin() + i, s.begin() + j);
                    i = j + 1;
                }
            }
            j++;
        }
        reverse(s.begin(), s.end());
    }
};

//T : O(2*N), S : O(N)
class Solution {
public:
    void reverseWords(string &s) {
        int len = s.length();
        stack<char> stk;
        string res;
        
        for(int i = len - 1; i >= 0; i--){
            if(s[i] == ' '){
                if(stk.size()){
                    while(stk.size()){
                        res.push_back(stk.top());
                        stk.pop();
                    }
                    res.push_back(' ');
                }
            }else{
                stk.push(s[i]);
            }
        }
        while(stk.size()){
            res.push_back(stk.top());
            stk.pop();
        }
        if(res.back() == ' ')
            res.pop_back();
        s = res;
    }
};
