//============================================================================
// You are climbing a stair case. It takes n steps to reach to the top.
//
// Each time you can either climb 1 or 2 steps.
// In how many distinct ways can you climb to the top?
//============================================================================

//T:O(N) S:(logN)
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1)
            return 1;
        int first_half = n&1 ? (n-1)>>1 : n>>1;
        int second_half = n&1 ? (n+1)>>1 : n>>1;
        //using one step OR two steps from first half to second half
        return climbStairs(first_half)*climbStairs(second_half) + climbStairs(first_half - 1)*climbStairs(second_half - 1); 
    }
};

//T:O(N) S:O(1)
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
        	return n;
        int a = 1; //two steps to reach c
        int b = 2; //one step to reach c
        int c;
        for (int i = 2; i < n; i++) {
            c = a + b; // from a to c plus from b to c
            a = b;
            b = c;
        }
        return c;
    }
};

//T: O(N) S: O(N)
class Solution {
public:
    int climbStairs(int n) {
        int *dp = new int[n+1];
        memset(dp, 0, sizeof(int)*(n+1));
        return climbStairsHelper(n, dp);
    }
    
    int climbStairsHelper(int n, int *dp) {
        if(n <= 0)
            return n==0 ? 1 : 0;
            
        if(dp[n] > 0)
            return dp[n];
            
        dp[n] = climbStairsHelper(n - 1, dp) + climbStairsHelper(n - 2, dp);
        return dp[n];
    }
};
