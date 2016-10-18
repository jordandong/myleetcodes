/*
Implement int sqrt(int x).

Compute and return the square root of x.

Hide Tags Math Binary Search
*/

class Solution {
public:
    int sqrt(int x) {
        long long lo = 0;
        //long long hi = x;
        long long hi = x/2 + 1;
        long long res = 0;
        while(lo <= hi){
            long long mid = lo + (hi - lo)/2;
            long long p = mid * mid;
            if(p == x)
                return (int)mid;
            else if(p < x)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return (int)hi;
    }
};
