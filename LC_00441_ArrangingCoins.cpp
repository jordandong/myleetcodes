/*
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.
Given n, find the total number of full staircase rows that can be formed.
n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:
n = 5
The coins can form the following rows:
¤
¤ ¤
¤ ¤
Because the 3rd row is incomplete, we return 2.

Example 2:
n = 8
The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤
Because the 4th row is incomplete, we return 3.
*/

class Solution {
public:
    int arrangeCoins(int n) {
        //x^2 + x + 1/4 = 2*n + 1/4
        //(x + 1/2)^2 = 2*n + 1/4
        //x = sqrt(2*n + 1/4) - 1/2
        int res = sqrt(2.0*n + 0.25) - 0.5;
        return res;
    }
};

class Solution {
public:
    int arrangeCoins(int n) {
        int lo = 0, hi = n;
        while (lo <= hi) {
            long long k = lo + (hi - lo) / 2;
            if ((k * (k + 1) / 2) > n ) {
                hi = k - 1;
            } else {
                lo = k + 1;
            }
        }
        return hi;
    }
};
