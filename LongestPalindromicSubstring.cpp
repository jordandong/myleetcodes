//============================================================================i
// Given a string S, find the longest palindromic substring in S. You may
// assume that the maximum length of S is 1000, and there exists one unique
// longest palindromic substring.
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0)
			return "";
        int maxi = 0;
        int maxl = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                int start = i - j;
                int end = i + 1;
                while (start >= 0 && end < n && s[start] == s[end]){
                    start--;
					end++;
				}
                start++;
				end--;
                int len = end - start + 1;
                if (len > maxl){
					maxi = start;
					maxl = len;
				}
            }
        }
        return s.substr(maxi, maxl);
    }
};

int main() {
    return 0;
}


//the below method is not true, since   abcdefgxxiiliigfedcba  v.s. abcdefgiiliixxgfedcba
class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = s.length();
        int dp[m+1];
        for(int l=0;l<=m;l++)
            dp[l]=0;
        
        int maxl=0;
        int maxj=0;
        
        for(int i=m-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
				if(s[i]==s[j])
                	dp[j+1] = dp[j]+ (s[i]==s[j]);
				else
					dp[j+1] = 0;

                if(dp[j+1]>maxl){
				    maxl=dp[j+1];
				    maxj=j+1;
			    }
            }
        }
        
        return s.substr(maxj-maxl,maxl);
    }
};
