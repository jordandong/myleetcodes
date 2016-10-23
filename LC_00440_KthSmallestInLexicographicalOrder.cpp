/*
Given integers n and k, find the lexicographically k-th smallest integer in the range from 1 to n.
Note: 1 ≤ k ≤ n ≤ 10^9.

Example:
Input:
n: 13   k: 2

Output:
10
Explanation:
The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
*/

class Solution {
public:
    int findKthNumber(int n, int k) {
        int result = 1;
        for(--k; k > 0; ) {
            int count = 0;
            for (long long first = result, last = first + 1;
                first <= n; // the interval is not empty
                first *= 10, last *= 10) {// increase a digit
                // valid interval = [first, last) union [first, n]
                count += min(n + 1LL, last) - first; // add the length of interval
            }
            
            if (k >= count) {
                // increase the current prefix
                ++result;
                k -= count;
            } else {   // not able to skip all of {result, result*, result**, result***, ...}
                // search more detailedly
                result *= 10;
                --k;
            }
        }
        return result;
    }
};
