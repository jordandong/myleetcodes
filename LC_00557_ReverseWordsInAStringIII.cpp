/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Note: In the string, each word is separated by single space and there will not be any extra space in the string.

Hide Tags String
*/

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        stack<char> stk;
        for (auto &c : s) {
            if (c == ' ') {
                while (!stk.empty()) {
                    res.push_back(stk.top());
                    stk.pop();
                }
                res.push_back(c);
            } else {
                stk.push(c);
            }
        }
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res; 
    }
};
