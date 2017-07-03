/*
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: 3
Output: False
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        int lo = 0, hi = sqrt(c);
        
        while (lo <= hi) {
            int rs = lo * lo + hi * hi;
            if (rs == c)
                return true;
            if (rs < c) {
                lo++;
            } else {
                hi--;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool judgeSquareSum(int c) {
        int lo = 0, hi = sqrt(c);
        do {
            int r = c - hi * hi;
            lo = sqrt(r);
            if (lo * lo == r)
                return true;
        } while (lo < hi--);
        return false;
    }
};
