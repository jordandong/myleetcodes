//============================================================================
// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...
//
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.
//
// Note: The sequence of integers will be represented as a string.
//
//
//============================================================================

#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n < 1)
        	return "";
        string res("1");
        while (n > 1) {
            ostringstream oss;
            int i = 0;
            while (i < res.size()) {
                int j = i;
                while (j < res.size() && res[j] == res[i])
                	j++;
                oss << (j-i) << res[i];
                i = j;
            }
            res = oss.str();
            n--;
        }
        return res;
    }
};

int main() {
    return 0;
}



class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 1)
            return ""; 
        string s="1";
        for (int i=1;i<n;i++){
            s=cAS(s);
        }
        return s;
    }

    string cAS(string &s){
        string res;
        char cur_str=s.at(0);
        int num=0;
        for (int i=0;i<s.length();i++)
        {
		if (cur_str==s.at(i))
			num++;
		else{
			stringstream ss;
			ss<<num<<cur_str;
			res+=ss.str();
			cur_str=s.at(i);
			num=1;
		} 		
        }
	if (num>0){
            stringstream ss;                   
            ss << num << cur_str;
            res += ss.str();
        }
        return res;
    }
};
