/*
Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.
(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

Example 1:
Input: N = 10
Output: 9

Example 2:
Input: N = 1234
Output: 1234

Example 3:
Input: N = 332
Output: 299

Note: N is an integer in the range [0, 10^9].
*/

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int n = s.length();
        int most_left = n;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] > s[i + 1]) {
                s[i] -= 1;
                most_left = i + 1;
            }
        }
        while (most_left < n)
            s[most_left++] = '9';
        return stoi(s);
    }
};
