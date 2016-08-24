/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Hide Tags Array Greedy
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int N = prices.size();
        if(N == 0)
            return 0;
        int res = 0;
        for(int i = 1; i < N; i++){
            int diff = prices[i] - prices[i - 1];
            res += diff > 0 ? diff : 0;
        }
        return res;
    }
};
