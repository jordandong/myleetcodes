/*
Given an integer, write a function to determine if it is a power of two.

Hint:
Could you solve it in O(1) time and using O(1) space?
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        n &= n - 1;
        return n == 0;
    }
};
