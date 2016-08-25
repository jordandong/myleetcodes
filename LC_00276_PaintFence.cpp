/*
There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color.
Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.
*/

class Solution {
public:
    int numWays(int n, int k) {
        if (n < 2 || !k)
            return n * k; 
        int s = k, d1 = k, d2 = k * (k - 1); 
        for (int i = 2; i < n; i++) {
            s = d2;
            d2 = (k - 1) * (d1 + d2);
            d1 = s;
        }
        return s + d2;
    }
};

class Solution {
public:
    int numWays(int n, int k) {
        if (n <= 0 || k <= 0)
            return 0;
        if (n <= 2)
            return pow(k, n);
        
        int same = k, diff = k*(k-1), res = k*k;
        for (int i = 3; i <= n; i++) {
            //at i, the num of last two same equal to the num of last two diff in previous step
            same = diff; 
            //at i, the num of last two different equal to the num of results in previous step multiply (k - 1)
            diff = res * (k - 1);
            res = same + diff;
        }
        return res;
    }
};
