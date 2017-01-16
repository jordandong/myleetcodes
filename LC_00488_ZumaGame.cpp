/*
Think about Zuma Game. You have a row of balls on the table, colored red(R), yellow(Y), blue(B), green(G), and white(W).
You also have several balls in your hand.

Each time, you may choose a ball in your hand, and insert it into the row (including the leftmost place and rightmost place).
Then, if there is a group of 3 or more balls in the same color touching, remove these balls.
Keep doing this until no more balls can be removed.

Find the minimal balls you have to insert to remove all the balls on the table.
If you cannot remove all the balls, output -1.

Examples:
Input: "WRRBBW", "RB"
Output: -1
Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW

Input: "WWRRBBWW", "WRBRW"
Output: 2
Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW -> empty

Input:"G", "GGGGG"
Output: 2
Explanation: G -> G[G] -> GG[G] -> empty 

Input: "RBYYBBRRB", "YRBGB"
Output: 3
Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] -> BB[B] -> empty 

Note:
1. You may assume that the initial row of balls on the table won’t have any 3 or more consecutive balls with the same color.
2. The number of balls on the table won't exceed 20, and the string represents these balls is called "board" in the input.
3. The number of balls in your hand won't exceed 5, and the string represents these balls is called "hand" in the input.
4. Both input strings will be non-empty and only contain characters 'R','Y','B','G','W'.

Hide Tags Depth-first Search
*/

class Solution {
private:
    unordered_map<char, int> m;
    int findMinStepHelper(string board) {
        if (board.empty())
            return 0;
        int minStep = INT_MAX;
        int i = 0;
        while (i < board.size()) {
            do {
                ++i;
            } while (i < board.size() && board[i] == board[i - 1]);
            char c = board[i - 1];
            if (m[c]) {
                --m[c];
                string nextBoard = board;
                nextBoard.insert(i, 1, c);
                findMinStepUpdate(nextBoard);
                int ans = findMinStepHelper(nextBoard);
                if (ans != INT_MAX)
                    minStep = min(minStep, 1 + ans);
                ++m[c];
            }
        }
        return minStep;
    }
    
    void findMinStepUpdate(string &board) {
        int i = 0;
        while (i < board.size()) {
            int start = i;
            do {
                ++i;
            } while (i < board.size() && board[i] == board[i - 1]);
            if (i - start >= 3) {
                board.erase(start, i - start);
                i = 0;
            }
        }
    }
public:
    int findMinStep(string board, string hand) {
        for (char c : hand)
            m[c]++;
        int ans = findMinStepHelper(board);
        return ans == INT_MAX ? -1 : ans;
    }
};
