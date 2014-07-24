/**
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

**/
//optimize the index to understand better
class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        if(len<2)
            return 0;
        int dp[len+1]; // min cut of at length i
        for(int i=0; i<=len;i++)
            dp[i]=INT_MAX;
        dp[0]=-1;
        
        bool dp1[len][len]; // from index i to j is palindrome
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(i>=j)
                    dp1[i][j]=true;
                else
                    dp1[i][j]=false;
            }
        }
            
        for(int i=0;i<len;i++){
            for(int j=i;j>=0;j--){
                if(s[j]==s[i]&&(i==0 || j==len-1 || dp1[j+1][i-1])){
                    dp[i+1]=min(dp[i+1], dp[j]+1);
                    dp1[j][i]=true;
                }
            }
        }
        return dp[len];
    }
    
};



class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        int dp[len+1];
        for(int i=1; i<=len;i++)
            dp[i]=INT_MAX;
        dp[0]=-1;
        
        bool dp1[len][len];
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(i==j)
                    dp1[i][j]=true;
                else
                    dp1[i][j]=false;
            }
        }
            
        for(int i=0;i<len;i++){
            for(int j=i-1;j>=-1;j--){
                if(s[j+1]==s[i]&&(j+1+2>=i||dp1[j+2][i-1])){
                    dp[i+1]=min(dp[i+1], dp[j+1]+1);
                    dp1[j+1][i]=true;
                }
            }
        }
        return dp[len];
    }
    
};
