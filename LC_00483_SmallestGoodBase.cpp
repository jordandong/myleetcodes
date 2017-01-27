/*
For an integer n, we call k>=2 a good base of n, if all digits of n base k are 1.

Now given a string representing n, you should return the smallest good base of n in string format. 

Example 1:
Input: "13"
Output: "3"
Explanation: 13 base 3 is 111.

Example 2:
Input: "4681"
Output: "8"
Explanation: 4681 base 8 is 11111.

Example 3:
Input: "1000000000000000000"
Output: "999999999999999999"
Explanation: 1000000000000000000 base 999999999999999999 is 11.

Note:
1. The range of n is [3, 10^18].
2. The string representing n is always valid and will not have leading zeros.

Hide Tags Binary Search Math
*/

/*
1 + k + k^2 + ... + k^m = n
n > k ^ m       --> k < n ** 1/m
n < (k + 1) ^ m --> k > n ** 1/m - 1
k = int(n ** 1/m)
verify 1 + k + k^2 + ... + k^m == n
*/

class Solution {
public:
    string smallestGoodBase(string n) {
        typedef unsigned long long ll;
        ll num = stol(n);
        for (ll m = log2(num); m >= 2; --m) {
            ll k = pow(num, 1.0 / m), sum = 0, f = 1;
            for (int i = 0; i < m + 1; i++, f *= k)
                sum += f;
            if (sum == num)
                return to_string(k);
        }
        return to_string(num - 1);
    }
};
