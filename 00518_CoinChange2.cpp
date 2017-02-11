/*
You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

Note: You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
Subscribe to see which companies asked this question.
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= amount; ++i) {
            for (int k = 1; k <= coins.size(); k++) {
                dp[i][k] = dp[i][k - 1]; 
                if (i - coins[k - 1] >= 0 && i > 0) //avoid 0 [0] case
                    dp[i][k] += dp[i - coins[k - 1]][k];//ways of fisrt k coins making i
            }
        }
        return dp[amount][coins.size()];        
    }
};

//TLE
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int res = 0;
        changeHelper(amount, coins, 0, res);
        return res;
    }
private:
    void changeHelper(int amount, vector<int>& coins, int k, int &res) {
        if (amount == 0) {
            res++;
            return;
        }
        if (k == coins.size())
            return;

        changeHelper(amount, coins, k + 1, res); //not use
        while (amount - coins[k] >= 0) { //use
            amount -= coins[k];
            changeHelper(amount, coins, k + 1, res);
        }
    }
};
