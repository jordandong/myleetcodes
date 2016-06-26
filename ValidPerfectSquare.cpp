/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Note: Do not use any built-in library function such as sqrt.

Example 1:
Input: 16
Returns: True

Example 2:
Input: 14
Returns: False

Hide Tags Binary Search
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0)
            return false;
        
        int lo = 0, hi = num / 2 + 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            long long val = (long long)mid * mid;
            if (val == num)
                return true;
            if (val < num)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return false;
    }
};

