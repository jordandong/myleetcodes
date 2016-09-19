/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:
Input:
3
Output:
3

Example 2:
Input:
11
Output:
0
Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

Hide Tags Math
*/

//T : O(logN), S : O(1)
class Solution {
public:
    int findNthDigit(int n) {
        int digit_len = 1;
        while (n > digit_len * 9 * pow(10, digit_len - 1)) {
            n -= digit_len * 9 * pow(10, digit_len - 1);
            ++digit_len;
        }

        const int num = pow(10, digit_len - 1) + (n - 1) / digit_len;

        int nth_digit = num / pow(10, (digit_len - 1) - (n - 1) % digit_len);
        nth_digit %= 10;

        return nth_digit;
    }
};

class Solution {
public:
    int findNthDigit(int n) {
        int digit_len = 1;
        while (n > digit_len * 9 * pow(10, digit_len - 1)) {
            n -= digit_len * 9 * pow(10, digit_len - 1);
            ++digit_len;
        }

        const int num = pow(10, digit_len - 1) + (n - 1) / digit_len;
        
        n -= ((n - 1) / digit_len * digit_len);

        int nth_digit = num / pow(10, (digit_len - 1) - (n - 1));
        nth_digit %= 10;
        return nth_digit;
    }
};
