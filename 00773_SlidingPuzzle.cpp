/*
On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

Examples:

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
Input: board = [[3,2,4],[1,5,0]]
Output: 14
Note:

board will be a 2 x 3 array as described above.
board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].
*/

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string des = "123450", src = "";
        for(int i = 0;i < board.size(); ++i) {
            for(int j = 0; j<board[0].size(); ++j)
                src += to_string(board[i][j]);
        }
        if(src == des)
            return 0;

        queue<string> q;
        vector<pair<int,int>> dir{{1, 0},{-1, 0},{0, 1},{0, -1}};
        set<string> v;
        int moves = 0;
        
        v.insert(src);
        q.push(src);
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                auto s = q.front();
                q.pop();
                int p0 = s.find('0');
                int x0 = p0 / 3, y0 = p0 % 3;
                for (auto &d: dir) {
                    int x = x0 + d.first, y = y0 + d.second;
                    if (x < 0 || x > 1 || y < 0 || y > 2)
                        continue;
                    auto p = x * 3 + y;
                    swap(s[p], s[p0]);
                    if(s == des)
                        return ++moves;
                    if(v.find(s) == v.end()) {
                        v.insert(s);
                        q.push(s);
                    }
                    swap(s[p], s[p0]);
                }
            }
            moves++;
        }
        return -1;
    }
};
