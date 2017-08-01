/*
Imagine you have a special keyboard with the following keys:
Key 1: (A): Prints one 'A' on screen.
Key 2: (Ctrl-A): Select the whole screen.
Key 3: (Ctrl-C): Copy selection to buffer.
Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.
Now, you can only press the keyboard for N times (with the above four keys), find out the maximum numbers of 'A' you can print on screen.

Example 1:
Input: N = 3
Output: 3
Explanation: 
We can at most get 3 A's on screen by pressing following key sequence:
A, A, A

Example 2:
Input: N = 7
Output: 9
Explanation: 
We can at most get 9 A's on screen by pressing following key sequence:
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V

Note:
1. 1 <= N <= 50
2. Answers will be in the range of 32-bit signed integer.
*/

class Solution {
public:
    int maxA(int N) {
        vector<int> dp(7, 0);
        dp[0] = 1;
        int MOD = 7;
        for (int i = 0; i < N; i++) {
            //dp[i] = dp[i - x] * (x - 1), c+a, c+c, c+v and repeat c+v, x >= 3
            //dp[i] = dp[i - x] * 2 * (x - 1 - 3), c+a, c+c, c+v , c+a, c+c, c+v, and repeat, x >= 6
            //2 * (x - 1 - 3) >= x - 1 , when x >= 7, so only consider x < 7
            dp[(i + 1) % MOD] = max(dp[(i + 1) % MOD], dp[i % MOD] + 1);
            dp[(i + 3) % MOD] = max(dp[(i + 3) % MOD], dp[i % MOD] * 2);
            dp[(i + 4) % MOD] = max(dp[(i + 4) % MOD], dp[i % MOD] * 3);
            dp[(i + 5) % MOD] = max(dp[(i + 5) % MOD], dp[i % MOD] * 4);
            dp[(i + 6) % MOD] = max(dp[(i + 6) % MOD], dp[i % MOD] * 5);
        }
        return dp[(N - 1) % MOD];
    }
};
