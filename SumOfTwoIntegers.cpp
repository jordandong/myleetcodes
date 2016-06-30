/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.

Hide Tags Bit Manipulation
Hide Similar Problems (M) Add Two Numbers
*/

class Solution {
public:
    int getSum(int a, int b) {
        int x, y;
        do{
            x = a & b;
            y = a ^ b;
            a = x << 1;
            b = y;
        } while (a);
        return y;
    }
};
