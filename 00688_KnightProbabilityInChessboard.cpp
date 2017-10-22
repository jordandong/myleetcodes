/*
On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).

A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

Horse

Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.

Example:
Input: 3, 2, 0, 0
Output: 0.0625
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
Note:
N will be between 1 and 25.
K will be between 0 and 100.
The knight always initially starts on the board.
*/

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(K + 1, 0)));
        vector<vector<int>> dir = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        
        for (int k = 0; k <= K; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    dp[i][j][k] = 0.0;
                    if ( k == 0) {
                        dp[i][j][0] = 1.0;
                    } else {
                        for (int d = 0; d < 8; ++d) {
                            int x = i + dir[d][0], y = j + dir[d][1];
                            if(x >= 0 && x < N && y >= 0 && y < N) {
                                dp[i][j][k] += dp[x][y][k - 1]/8;
                            }
                        }
                    }
                }
            }
        }
        return dp[r][c][K];
    }
};

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(K + 1, 0)));
        knightProbabilityHelper(N, K, r, c, dp);
        return dp[r][c][K];
    }
private:
    double knightProbabilityHelper(int N, int k, int r, int c, vector<vector<vector<double>>> &dp) {
        vector<vector<int>> dir = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

        if (r < 0 || r >= N  || c < 0 || c >= N)
            return 0;
        if (k == 0)
            dp[r][c][k] = 1.0;
        if (dp[r][c][k] != 0)
            return dp[r][c][k];
        double res = 0;
        for (auto d : dir)
            res += knightProbabilityHelper(N, k - 1, r + d[0], c + d[1], dp) / 8;
        dp[r][c][k] = res;
        return dp[r][c][k];
    }
};
