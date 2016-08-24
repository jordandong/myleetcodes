/*
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the n-th round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:
Given n = 3. 
At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 
So you should return 1, because there is only one bulb is on.

Hide Tags Brainteaser
*/

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n); //x^x < n (x = 1, 2, 3, ...) will be touched by odd times
    }
};

class Solution {
public:
    int bulbSwitch(int n) {
        long long lo = 0;
        long long hi = n/2 + 1;
        long long res = 0;
        while(lo <= hi) {
            long long mid = lo + (hi - lo)/2;
            long long p = mid * mid;
            if(p == n)
                return (int)mid;
            else if(p < n)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return (int)hi;
    }
};
