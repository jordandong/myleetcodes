/*
Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note that 1 is typically treated as an ugly number.

Hint:
1. The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
2. An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
3. The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
A4. ssume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Hide Tags Dynamic Programming Heap Math
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        long long res[n];
        res[0] = 1;
        int base2_idx = 0, base3_idx = 0, base5_idx = 0;
        for (int i = 1; i < n; i++) {
            res[i] = min(min(res[base2_idx] * 2, res[base3_idx] * 3), res[base5_idx] * 5);
            //if the minimum is used, increasing the base in order to generate bigger one in next round
            if(res[i] / res[base2_idx] == 2)
                base2_idx++;
            if(res[i] / res[base3_idx] == 3)
                base3_idx++;
            if(res[i] / res[base5_idx] == 5)
                base5_idx++;
        }
        return res[n - 1];
    }
};
