/*
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Tags Math
*/

/*
There exists a pretty fast method for integers of limited size (e.g. 32-bit integers).
Note that for an integer N that is a power of 3 the following is true:
    For any M <= N that is a power of 3, M divides N.
    For any M <= N that is not a power 3, M does not divide N.
    The biggest power of 3 that fits into 32 bits is 3^19.
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && ((int)pow(3, 19) % n == 0);
    }
};

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
