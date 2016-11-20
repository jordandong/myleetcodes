/*
In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.

You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.

Example

Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.
*/

/*if it is allowed to use the same value more than once :
  if desiredTotal % (maxChoosableInteger + 1) == 0 , then P1 1 always lose
  if not 0, P1 could get desiredTotal % (maxChoosableInteger + 1) first, then no matter P2 gets what, P1 could get maxChoosableInteger + 1 - P2get to reach desiredTotal.
 */

//T : O(maxChoosableInteger!), S : O(1 << maxChoosableInteger)
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger * (maxChoosableInteger + 1) < 2 * desiredTotal)
            return false;
        int canUse = (1 << (maxChoosableInteger + 1)) - 2;
        unordered_map<int, bool> dp; 
        return canIWinHepler(canUse, desiredTotal, dp);
    }
    
    bool canIWinHepler(int &canUse, int desiredTotal, unordered_map<int, bool> &dp) {
        if (dp.find(canUse) != dp.end())
            return dp[canUse];
        for (int i = 20; i > 0; i--) {
            int to_use = (1 << i);
            if (canUse & to_use) {
                if (i >= desiredTotal) {
                    dp[canUse] = true;
                    return true;
                }
                canUse ^= to_use;
                if (false == canIWinHepler(canUse, desiredTotal - i, dp)) {
                    canUse |= to_use;
                    dp[canUse] = true;
                    return true;
                }
                canUse |= to_use;
            }
        }
        dp[canUse] = false;
        return false;
    }
};
