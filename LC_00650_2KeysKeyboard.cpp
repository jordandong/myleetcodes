/*
Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:
1. Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
2. Paste: You can paste the characters which are copied last time.

Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted.
Output the minimum number of steps to get n 'A'.

Example 1:
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.

Note:
1. The n will be in the range [1, 1000].
*/

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, n);
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (i % j == 0)
                    dp[i] = min(dp[i], dp[j] + i / j);
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
        while (n > 1) {
            int i = 0;
            for (i = 0; i < primes.size(); i++) {
                if (n % primes[i] == 0) {
                    ans += primes[i]; //adding fac
                    n /= primes[i]; //finding next fac
                    break;
                }
            }
            if (i == primes.size()) { //primes
                ans += n;
                n /= n;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        while (n > 1) {
            int d = 2;
            while (d <= n && n % d)
                ++d;
            ans += d;
            n /= d;
        }
        return ans;
    }
};
