/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        int base = 5;
        while(n){
            res += (n / base);
            n /= base;
        }
        return res;
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        int a = 1;
        long long base = pow(5, a);
        int res = 0;
        while(base <= n){
            res += (n / base);
            base = pow(5, ++a);
        }
        return res;
    }
};
