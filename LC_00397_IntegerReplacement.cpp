/*
Given a positive integer n and you can do operations as follow:
1. If n is even, replace n with n/2.
2. If n is odd, you can replace n with either n + 1 or n - 1.
3. What is the minimum number of replacements needed for n to become 1?

Example 1:
Input:
8
Output:
3
Explanation:
8 -> 4 -> 2 -> 1

Example 2:
Input:
7
Output:
4
Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1

Hide Tags Math
*/

class Solution {
public:
    int integerReplacement(int n) {
        long long num = n;
        int res = 0;
        while (num != 1) {
            long long r = num & 0x3;
            //make more power of 2 ASAP
            if (r == 1 || num == 3)
                num--;
            else if (r == 3)
                num++;
            else
                num /= 2;
            res++;
        }
        return res;
    }
};

class Solution {
public:
    int integerReplacement(int n) {
        return integerReplacementHelper(n);
    }
    
    int integerReplacementHelper(long long n) {
        if (n == 1)
            return 0;
        if (n & 1)
            return min(integerReplacementHelper(n - 1), integerReplacementHelper(n + 1)) + 1;
        else
            return integerReplacementHelper(n/2) + 1;
    }
};
