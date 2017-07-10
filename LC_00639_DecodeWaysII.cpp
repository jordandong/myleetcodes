/*
A message containing letters from A-Z is being encoded to numbers using the following mapping way:
'A' -> 1
'B' -> 2
...
'Z' -> 26

Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

Also, since the answer may be very large, you should return the output mod 10^9 + 7.

Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".

Example 2:
Input: "1*"
Output: 9 + 9 = 18

Note:
1. The length of the input string will fit in range [1, 105].
2. The input string will only contain the character '*' and digits '0' - '9'.
*/

class Solution {
public:
    int numDecodings(string s) {
        int MOD = 1000000007;
        long e_any = 1, e_1 = 0, e_2 = 0;
        long f_any, f_1, f_2;
        for (auto  c : s) {
            if (c == '*') {
                f_any = 9 * e_any + 9 * e_1 + 6 * e_2; //use * as one digit + 1* + 2*
                f_1 = e_any; //xxx1, 1 is not used
                f_2 = e_any; //xxx2, 2 is not used
            } else {
                f_any = (c > '0') * e_any + e_1 + (c <= '6') * e_2; //user num as one digit + 1* + 2*
                f_1 = (c == '1') * e_any; //xxx1, 1 is not used
                f_2 = (c == '2') * e_any; //xxx2, 2 is not used
            }
            e_any = f_any % MOD;
            e_1 = f_1;
            e_2 = f_2;
        }
        return e_any;
    }
};
