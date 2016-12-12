/*
Given a non-empty string, encode the string such that its encoded length is the shortest.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.

Note:
1. k will be a positive integer and encoded string will not be empty or have extra space.
2. You may assume that the input string contains only lowercase English letters. The string's length is at most 160.
3. If an encoding process does not make the string shorter, then do not encode it. If there are several solutions, return any of them is fine.

Example 1:
Input: "aaa"
Output: "aaa"
Explanation: There is no way to encode it such that it is shorter than the input string, so we do not encode it.

Example 2:
Input: "aaaaa"
Output: "5[a]"
Explanation: "5[a]" is shorter than "aaaaa" by 1 character.

Example 3:
Input: "aaaaaaaaaa"
Output: "10[a]"
Explanation: "a9[a]" or "9[a]a" are also valid solutions, both of them have the same length = 5, which is the same as "10[a]".

Example 4:
Input: "aabcaabcd"
Output: "2[aabc]d"
Explanation: "aabc" occurs twice, so one answer can be "2[aabc]d".

Example 5:
Input: "abbbabbbcabbbabbbc"
Output: "2[2[abbb]c]"
Explanation: "abbbabbbc" occurs twice, but "abbbabbbc" can also be encoded to "2[abbb]c", so one answer can be "2[2[abbb]c]".
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string encode(string s) {
    	unordered_map<string, string> dp;
    	int N = s.length();
    	if (N < 5)
    		return s;
        return encodeHelper(s, dp);
    }
private:
	string encodeHelper(string s, unordered_map<string, string> &dp) {
		int N = s.length();
		if (N < 5)
			return s;
		if (dp.find(s) != dp.end())
			return dp[s];
		string ans = s;
    	for (int l = 1; l <= N; l++) {
    		string res = encodeHelperCompress(s.substr(0, l), dp) + encodeHelper(s.substr(l), dp);
    		if (res.length() < ans.length())
    			ans = res;
    	}
    	dp[s] = ans;
        return ans;
	}
	
	string encodeHelperCompress(string s, unordered_map<string, string> &dp) {
		int N = s.length();
		if (N < 5)
			return s;
		if (dp.find(s) != dp.end())
			return dp[s];
		
		string ans = s;
        for (int x = 1; x < N / 2 + 1; x++) {
            if (N % x || false == isRepeated(x, s))
            	continue;
            string res = to_string(N / x) + '[' + encodeHelper(s.substr(0, x), dp) + ']';
            if (res.length() < ans.length())
            	ans = res;
        }
        return ans;
	}
	
	bool isRepeated(int x, string s) {
		int i = 0, j = 0, N = s.length();
		while (j < N) {
			if (s[i] != s[j])
				return false;
			i = (i + 1) % x;
			j++;
		}
		return true;
	}
};

int main() {
	Solution s;
	cout<<s.encode("aaa")<<endl;
	cout<<s.encode("aaaaa")<<endl;
	cout<<s.encode("aaaaaaaaaa")<<endl;
	cout<<s.encode("aabcaabcd")<<endl;
	cout<<s.encode("abbbabbbc")<<endl;
	cout<<s.encode("abbbabbbcabbbabbbc")<<endl;

	return 0;
}

aaa
5[a]
a9[a]
2[aabc]d
2[abbb]c
2[2[abbb]c]
