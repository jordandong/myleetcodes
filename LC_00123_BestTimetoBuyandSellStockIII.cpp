/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Hide Tags Array Dynamic Programming
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int N = prices.size();
        if(N == 0)
            return 0;
        int sum[N];
        int mi = prices[0];
        int mx = prices[N - 1];
        int mx_sum = 0;
        int res = 0;
        sum[0] = 0;

        for(int i = 1; i < N; i++){
            mi = min(mi, prices[i]);
            sum[i] = max(sum[i - 1], prices[i] - mi);//1st transaction sell <= day i, max profit
        }
        
        for(int i = N - 1; i >= 0; i--){
            mx = max(mx, prices[i]);
            mx_sum = max(mx_sum, mx - prices[i]); //2nd transaction buy >= day i, max profit
            res = max(res, sum[i] + mx_sum);
        }
        return res;
    }
};
