/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
1. You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
2. After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

Example:
prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]

Credits:
Special thanks to @peisi for adding this problem and creating all test cases.

Hide Tags Dynamic Programming
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN;
        int sell = 0;
        int prev_sell = 0;
        int prev_buy = 0;
        for (int price : prices) {
            prev_buy = buy;
            buy = max(prev_sell - price, buy); //action buy or cooldown
            prev_sell = sell;
            sell = max(prev_buy + price, sell); //action sell or cooldown
        }
        return sell;    
    }
};
