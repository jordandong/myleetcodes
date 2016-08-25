/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Hide Tags String
*/

class Solution {
public:
    string countAndSay(int n) {
        if (n < 1)
            return "";
        string res("1");
        while (n > 1) {
            string tmp = "";
            int i = 0;
            while (i < res.size()) {
                int j = i;
                while (j < res.size() && res[j] == res[i])
                    j++;
                tmp.push_back('0' + (j - i));
                tmp.push_back(res[i]);
                i = j;
            }
            res = tmp;
            n--;
        }
        return res;
    }
};

class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 1)
            return ""; 
        string s = "1";
        for (int i = 1; i < n; i++)
            s = cAS(s);
        return s;
    }

    string cAS(string &s){
        string res = "";
        int j = 0;
        int i = 0;
        for(i = 0; i < s.length(); i++){
            if(s[i] != s[j]){
                res.push_back('0'+ (i - j));
                res.push_back(s[j]);
                j = i;
            } 		
        }
        res.push_back('0'+ (i - j));
        res.push_back(s[j]);
        return res;
    }
};
