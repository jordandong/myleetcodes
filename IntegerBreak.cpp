/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2.
Hint:
There is a simple O(n) solution to this problem.
You may check the breaking results of n ranging from 7 to 10 to discover the regularities.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Hide Tags Dynamic Programming Math
*/
/*
Simplifying 2*(f-2) >= f to f >= 4 shows that breaking any factor f >= 4 into factors 2 and f-2 won't hurt the product.
If an optimal product contains a factor f >= 4, then you can replace it with factors 2 and f-2 without losing optimality, as 2*(f-2) = 2f-4 >= f.
So you never need a factor greater than or equal to 4, meaning you only need factors 1, 2 and 3 
(and 1 is of course wasteful and you'd only use it for n=2 and n=3, where it's needed).
*/

class Solution {
public:
    int integerBreak(int n) {
        switch (n) {
            case 2:
                return 1;
            case 3:
                return 2;
            default:
                int m = n % 3;
                if(m == 0)
                    return (int)pow(3, n/3);
                else if (m == 1)
                    return 4 * (int)pow(3, n/3 - 1);
                else 
                    return 2 * (int)pow(3, n/3);
        }
    }
};

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;

        int res = 1;
        while (n > 2){
            res *= 3;
            n -= 3;
        }
        
        if(n == 0)
            return res;
        if(n == 1)
            return (res / 3 ) * 4;
        if(n == 2)
            return res * 2;
    }
};

class Solution {
public:
    int integerBreak(int n) {
       vector<int> dp(n + 1, 0);
       dp[1] = 1;
       for (int i = 2; i <= n; i++) {
           for (int j = 1; j <= i/2; j ++)
               dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i - j]));
       }
       return dp[n];
    }
};
