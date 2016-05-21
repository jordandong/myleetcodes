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

//use O(1) string space
class Solution {
private:
    int len;
    string ss;
public:
    bool canWin(string s) {
        len = s.size();
        ss = s;
        return canWin();
    }
    
    bool canWin() {
        for (int is = 0; is <= len - 2; ++is) {
            if (ss[is] == '+' && ss[is+1] == '+') {
                ss[is] = '-'; 
                ss[is+1] = '-';
                bool wins = !canWin(); 
                ss[is] = '+';
                ss[is+1] = '+';
                if (wins)
                    return true;
            }
        }
        return false;
    }
};

// The best theory solution (DP, O(n + c^2)) could be seen here:
// https://leetcode.com/discuss/64344/theory-matters-from-backtracking-128ms-to-dp-0ms
class Solution {
public:
    bool canWin(string s) {
        replace(s.begin(), s.end(), '-', ' ');
        istringstream in(s);
        int g_final = 0;
        vector<int> g;  // Sprague-Grundy function of 0 ~ maxlen, O(n) space
        for (string t; in >> t; ) {  // Split the string
            int p = t.size();
            while (g.size() <= p) {  // O(c) time
                string x = t;
                int i = 0, j = g.size() - 2;
                while (i <= j) {  // The S-G value of all subgame states, O(c) time
                    // Theorem 2: g[game] = g[subgame1]^g[subgame2]^g[subgame3]...;
                    x[g[i++] ^ g[j--]] = '-';
                }
                // Find first missing number.
                g.push_back(x.find('+'));
            }
            g_final ^= g[p];
        }
        return g_final;  // Theorem 1: First player must win iff g(current_state) != 0
    }
};
