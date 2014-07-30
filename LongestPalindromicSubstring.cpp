//============================================================================i
// Given a string S, find the longest palindromic substring in S. You may
// assume that the maximum length of S is 1000, and there exists one unique
// longest palindromic substring.
//============================================================================


class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = s.size();
        if(N==1)
            return s;
        
        bool dp[N][N]; // dp[i][j] means start from i and end at j
        int m = 0;
        int start;
        for(int i =0; i<N;i++){
            for(int j=0; j<N; j++){
                dp[i][j] = false;
            }
        }
        
        for(int i= N-1; i>=0;i--){
            for(int j=i; j<N; j++){
                if(i==j)
                    dp[i][j]=true;
                else if(j-i==1)
                    dp[i][j]=s[i]==s[j];
                else
                    dp[i][j] = dp[i+1][j-1] && s[i]==s[j];
                if(dp[i][j]&& j-i+1>m){
                    m = j-i+1;
                    start=i;
                }
            }
        }
        return s.substr(start, m);
    }
};

//brute force
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


class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = s.size();
        if(N==1)
            return s;
        
        bool dp[N][N+1];
        int m = 0;
        int start;
        for(int i =0; i<N;i++){
            for(int k=0; k+i<=N; k++){
                if(k==1||k==0)
                    dp[i][k] = true;
                else
                    dp[i][k] = false;
            }
        }
        
        for(int k=2; k<=N;k++){ // dp[i][k] means start from i and length is k
            for(int i=0; i+k<=N; i++){
                dp[i][k] = dp[i+1][k-2] && s[i]==s[i+k-1];
                if(dp[i][k]){
                    m = max(m, k);
                    start=i;
                }
            }
        }
        return s.substr(start, m);
    }
};



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
