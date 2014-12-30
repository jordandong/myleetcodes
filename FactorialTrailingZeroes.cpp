/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int a = 1;
        int base = pow(5, a);
        int res = 0;
        while(base<=n){
            res+=(n/base);
            base = pow(5, ++a);
            //every 5 has one zero, 5^a has a-1 extra zeros
        }
        return res;
    }
};
