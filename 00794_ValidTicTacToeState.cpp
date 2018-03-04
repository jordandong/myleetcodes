/*
A Tic-Tac-Toe board is given as a string array board. Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.

Here are the rules of Tic-Tac-Toe:

Players take turns placing characters into empty squares (" ").
The first player always places "X" characters, while the second player always places "O" characters.
"X" and "O" characters are always placed into empty squares, never filled ones.
The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Example 1:
Input: board = ["O  ", "   ", "   "]
Output: false
Explanation: The first player always plays "X".

Example 2:
Input: board = ["XOX", " X ", "   "]
Output: false
Explanation: Players take turns making moves.

Example 3:
Input: board = ["XXX", "   ", "OOO"]
Output: false

Example 4:
Input: board = ["XOX", "O O", "XOX"]
Output: true
Note:

board is a length-3 array of strings, where each string board[i] has length 3.
Each board[i][j] is a character in the set {" ", "X", "O"}.
*/

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int Xs = 0, Os = 0, diag = 0, anti_diag = 0, r[3] = {0, 0, 0}, c[3] = {0, 0, 0};
        bool Xwin = false, Owin = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].length(); j++) {
                if (board[i][j] == ' ')
                    continue;
                int v = (board[i][j] == 'X') ? 1 : -1;
                r[i] += v;
                c[j] += v;
                if (i == j)
                    diag += v;
                if (i + j == board.size() - 1)
                    anti_diag += v;
                Xwin |= ((r[i] == 3) || (c[j] == 3) || (diag == 3) || (anti_diag == 3));
                Owin |= ((r[i] == -3) || (c[j] == -3) || (diag == -3) || (anti_diag == -3));
                Xs += v > 0 ? 1 : 0;
                Os += v < 0 ? 1 : 0;
            }
        }
        if ((Os > Xs) || (Xs > Os + 1) || (Xwin && Xs == Os) || (Owin && Xs > Os))
            return false;
        return true;
    }
};
