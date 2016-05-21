/*
You are playing the following Flip Game with your friend: 
Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--".
The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.
For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity.
*/

//T : O(2^N) - worst case , S : O(N) - stack
class Solution {
public:
    bool canWin(string s) {
        for (int i = -1; (i = s.find("++", i + 1)) >= 0; )
            if (!canWin(s.substr(0, i) + '-' + s.substr(i + 2)))
                return true;
        return false;
    }
};

