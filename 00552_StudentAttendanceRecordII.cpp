/*
Given a positive integer n, return the number of all possible attendance records with length n, which will be regarded as rewardable. The answer may be very large, return it after mod 109 + 7.

A student attendance record is a string that only contains the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

Example 1:
Input: n = 2
Output: 8 
Explanation:
There are 8 records with length 2 will be regarded as rewardable:
"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" won't be regarded as rewardable owing to more than one absent times. 
Note: The value of n won't exceed 100,000.
*/

class Solution {
public:
    int checkRecord(int n) {
        long M = 1000000007;
        long a0l0 = 1, a0l1 = 0, a0l2 = 0, a1l0 = 0, a1l1 = 0, a1l2 = 0;
        for (int i = 0; i <= n; i++) {
            long a0l0_ = (a0l0 + a0l1 + a0l2) % M; //..P/L/LL + P
            a0l2 = a0l1; // ..L + L
            a0l1 = a0l0; // ..P + L
            a0l0 = a0l0_; // ..L/P + P
            long a1l0_ = (a0l0 + a1l0 + a1l1 + a1l2) % M; //...L/P + A plus A...P/L/LL + P
            a1l2 = a1l1; //A...L + L
            a1l1 = a1l0; //A...P + L
            a1l0 = a1l0_;//...L/P + A plus  A...P/L/LL + P
        }
        return (int) a1l0;
    }
};
