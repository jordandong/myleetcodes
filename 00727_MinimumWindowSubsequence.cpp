/*
Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:
Input: 
S = "abcdebdde", T = "bde"
Output: "bcde"
Explanation: 
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of T in the window must occur in order.
Note:

All the strings in the input will only contain lowercase letters.
The length of S will be in the range [1, 20000].
The length of T will be in the range [1, 100].
*/

class Solution {
public:
    string minWindow(string S, string T) {
        int n = S.length();
        int start = 0, mi = n;
        vector<vector<int>> next(n + 1, vector<int>(26, -1));
        //at pos i, the next char appear at which pos
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++)
                next[i][j] = next[i + 1][j];
            next[i][S[i] - 'a'] = i;
        }
        for (int left = 0; left < n; left++) {
            int right = left;
            for (int j = 0; j < T.length(); j++) {
                right = next[right][T[j] - 'a'];
                if (right == -1)
                    break;
                right++;//update to next pos for next searching
            }
            if (right != -1 && right - left < mi) {
                mi = right - left;
                start = left;
            }
        }
        if (mi == n)
            return "";
      return S.substr(start, mi);  
    }
};
