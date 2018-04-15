/*
Your car starts at position 0 and speed +1 on an infinite number line.  (Your car can go into negative positions.)

Your car drives automatically according to a sequence of instructions A (accelerate) and R (reverse).

When you get an instruction "A", your car does the following: position += speed, speed *= 2.

When you get an instruction "R", your car does the following: if your speed is positive then speed = -1 , otherwise speed = 1.  (Your position stays the same.)

For example, after commands "AAR", your car goes to positions 0->1->3->3, and your speed goes to 1->2->4->-1.

Now for some target position, say the length of the shortest sequence of instructions to get there.

Example 1:
Input: 
target = 3
Output: 2
Explanation: 
The shortest instruction sequence is "AA".
Your position goes from 0->1->3.
Example 2:
Input: 
target = 6
Output: 5
Explanation: 
The shortest instruction sequence is "AAARA".
Your position goes from 0->1->3->7->7->6.
 

Note:

1 <= target <= 10000.
*/

class Solution {
public:
    int racecar(int target) {
        int N = floor(log2(target)) + 1;
        vector<int> dp(pow(2, N), INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= target; i++) {
            int n = floor(log2(i)) + 1;
            //i==2^n - 1, this case, n is the best way, 1 + 2 + 4 + ...
            if (i == pow(2, n) - 1 ) {
                dp[i] = n;
                continue;
            }
            //2^(n - 1) - 1 < i < 2^n - 1, there are two ways to arrive at i:
            //Use n A to arrive at 2^n - 1 first, then use R to change the direction, by here there are n + 1 operations (n A and one R)
            //then the remaining is same as dp[2^n - 1 - i]
            if (pow(2, n - 1) - i < i) {
                dp[i] = min(dp[i], dp[pow(2, n) - 1 - i] + n + 1);
            }
            //Use n - 1 A to arrive at 2^(n - 1) - 1 first, then R to change the direction
            //use m A to go backward, then use R to change the direction again to move forward
            //by here there are n - 1 + 2 + m = n + m + 1 operations (n - 1 A, two R, m A);
            //current position is 2^(n - 1) - 1 - (2^m - 1) = 2^(n - 1) - 2^m;
            //the remaining operations is same as dp[i - (2^(n - 1) - 1) + (2^m - 1)] = dp[i - 2^(n - 1) + 2^m)].
            for (int m = 0; m < n - 1; m++) {
                dp[i] = min(dp[i], dp[i - pow(2, n - 1) + pow(2, m)] + n + m + 1);
            }
        }
        return dp[target];
    }
};
