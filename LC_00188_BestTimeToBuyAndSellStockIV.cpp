/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Hide Tags Dynamic Programming
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
            return 0; 
            
        if(k > n/2)
            return bigK(prices);
        //k = min(k, n/2); //can not pass TLE
        
        vector<vector<int> > dp(2, vector<int>(n, 0));
        int c = 0;
        for (int i = 1; i <= k; i++) {
            int bM = dp[c][0] - prices[0];//trans k start: buy at index 0, the max sum
            for (int j = 1; j < n; j++) {
                dp[c^1][j] = max(dp[c^1][j - 1], prices[j] + bM);
                //trans k done before j - 1 OR trans k which sells at j
                bM =  max(bM, dp[c][j] - prices[j]);
                //trans k + 1 start: buy at index j  OR buy before j, the max sum 
            }
            c^=1;
        }
        return dp[c][n - 1];
    }

    int bigK(vector<int> &prices) {
	    int res = 0;
        for(int i = 1; i < prices.size(); i++)
            if(prices[i] > prices[i - 1])
                res += prices[i] - prices[i - 1];
        return res;
    }
};
