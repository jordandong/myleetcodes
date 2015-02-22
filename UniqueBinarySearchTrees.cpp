/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

Hide Tags Tree Dynamic Programming
*/

//DP
class Solution {
public:
    int numTrees(int n){
        int dp[n+1];
        memset(dp, 0, (n+1)*sizeof(int));
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j]*dp[i - j - 1];
                //j==0, insert the ith into the top as root
                //j==i-1, insert the ith into the rightmost of leaf
                //j==1~i-2, insert the ith into middle which is the biggest, so one situation  
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int numTrees(int n) {
        int dp[n + 1];
        memset(dp, 0, (n+1)*sizeof(int));
        dp[0]=1;
        return numTreesHelper(n, dp);
        
    }
    
    int numTreesHelper(int n, int* dp){
        if(dp[n] != 0)
            return dp[n];
        for(int i = 1; i <= n; i++){
            dp[n] += numTreesHelper(i - 1, dp)*numTreesHelper(n - i, dp);
        }
        return dp[n];
    }
};

//Non DP
class Solution {
public:
    int numTrees(int n) {
        return numTreesHelper(1, n);
    }
    
    int numTreesHelper(int start, int end){
        if(start >= end)
            return 1;
        int res = 0;
        for(int k = start; k <= end; k++){
            int left = numTreesHelper(start, k - 1);
            int right = numTreesHelper(k + 1, end);
            res += left*right;
        }
        return res;
    }
};

class Solution {
public:
    int numTrees(int n){
        if(n < 2)
            return 1;
        int res = 0;
        for(int i = 0; i < n; i++)
            res += numTrees(i)*numTrees(n - i - 1);
		//ith node as root, 0 to i-1th nodes form a left tree and i+1 to n-1 nodes form right tree
        return res;
    }
};
