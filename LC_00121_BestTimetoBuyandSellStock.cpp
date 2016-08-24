/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Hide Tags Array Dynamic Programming
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int N = prices.size();
        if(N == 0)
            return 0;
        int mi = prices[0];
        int res = 0;
        for(auto e : prices){
            mi = min(e, mi);
            res = max(res, e - mi);
        }
        return res;
    }
};
