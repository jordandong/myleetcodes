/*
There is an m by n grid with a ball.
Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right).
However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary.
The answer may be very large, return it after mod 10^9 + 7.

Example 1:
Input:m = 2, n = 2, N = 2, i = 0, j = 0
Output: 6
Explanation:
one time:
O *  O *
* *  * *
two times:
O *  O *  0 *  0 *
* *  * *  * *  * *

Example 2:
Input:m = 1, n = 3, N = 3, i = 0, j = 1
Output: 12
Explanation:
one time:
* O *  * O *
two times:
* O *  * O *
three times:
* O *  * O *  * O *

Note:
1. Once you move the ball out of boundary, you cannot move it back.
2. The length and height of the grid is in range [1,50].
3. N is in range [0,50].

Hide Tags Dynamic Programming Depth-first Search
*/

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int dp[N + 1][m + 1][n + 1] = {};
        for (auto Ni = 1; Ni <= N; ++ Ni) {
            for (auto mi = 0; mi < m; ++mi) {
                for (auto ni = 0; ni < n; ++ni) {
                    dp[Ni][mi][ni] = ((long long)(mi == 0 ? 1 : dp[Ni - 1][mi - 1][ni]) + //up
                                                 (mi == m - 1? 1 : dp[Ni - 1][mi + 1][ni]) + //down
                                                 (ni == 0 ? 1 : dp[Ni - 1][mi][ni - 1]) + //left
                                                 (ni == n - 1 ? 1 : dp[Ni - 1][mi][ni + 1])) //right
                                                 % 1000000007;
                }
            }
        }
        return dp[N][i][j];
    }
};

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int dp[2][50][50] = {};
        for (auto Ni = 1; Ni <= N; ++ Ni) {
            for (auto mi = 0; mi < m; ++mi) {
                for (auto ni = 0; ni < n; ++ni) {
                    dp[(Ni + 1) % 2][mi][ni] = ((long long)(mi == 0 ? 1 : dp[Ni % 2][mi - 1][ni]) + //up
                                                 (mi == m - 1? 1 : dp[Ni % 2][mi + 1][ni]) + //down
                                                 (ni == 0 ? 1 : dp[Ni % 2][mi][ni - 1]) + //left
                                                 (ni == n - 1 ? 1 : dp[Ni % 2][mi][ni + 1])) //right
                                                 % 1000000007;
                }
            }
        }
        return dp[(N + 1) % 2][i][j];
    }
};
