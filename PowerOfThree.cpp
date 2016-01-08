/*
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Tags Math
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        //n = abs(n);
        if (n == 0)
            return false;
        if (n == 1)
            return true;
        for(int s = sqrt(n); s * s == n; n = s, s = sqrt(n));
        return (n % 3 == 0) ? isPowerOfThree(n / 3) : false;
    }
};
