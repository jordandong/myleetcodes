/*
An N x N board contains only 0s and 1s. In each move, you can swap any 2 rows with each other, or any 2 columns with each other.

What is the minimum number of moves to transform the board into a "chessboard" - a board where no 0s and no 1s are 4-directionally adjacent? If the task is impossible, return -1.

Examples:
Input: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
Output: 2
Explanation:
One potential sequence of moves is shown below, from left to right:

0110     1010     1010
0110 --> 1010 --> 0101
1001     0101     1010
1001     0101     0101

The first move swaps the first and second column.
The second move swaps the second and third row.


Input: board = [[0, 1], [1, 0]]
Output: 0
Explanation:
Also note that the board with 0 in the top left corner,
01
10

is also a valid chessboard.

Input: board = [[1, 0], [1, 0]]
Output: -1
Explanation:
No matter what sequence of moves you make, you cannot end with a valid chessboard.
Note:

board will have the same number of rows and columns, a number in the range [2, 30].
board[i][j] will be only 0s or 1s.
*/

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int res = 0;
        int N = board.size();
        
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            if (board[0][i] == 0) ++sum;
        }
        sum = min(sum, N-sum);
        if (sum != N/2) return -1;
        
        sum = 0;
        for (int i = 1; i < N; ++i) {
            int sum00 = 0;
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == board[0][j]) ++sum00;
            }
            if (sum00 == 0) ++sum;
            else if (sum00 != N) return -1;
        }
        sum = min(sum, N-sum);
        if (sum != N/2) return -1;
        
        int cnt0 = 0;
        for (int i = 0; i < N; ++i) {
            if (board[0][i] == i%2) ++cnt0;
        }
        cnt0 = min(cnt0, N-cnt0);
        if (cnt0%2 == 0) res += cnt0/2;
        else res += (N-cnt0)/2;
        
        cnt0 = 0;
        for (int i = 0; i < N; ++i) {
            if (board[i][0] == i%2) ++cnt0;
        }
        cnt0 = min(cnt0, N-cnt0);
        if (cnt0%2 == 0) res += cnt0/2;
        else res += (N-cnt0)/2;
        
        return res;
        
    }
};
