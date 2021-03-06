/*
Given a positive integer a, find the smallest positive integer b whose multiplication of each digit equals to a.
If there is no answer or the answer is not fit in 32-bit signed integer, then return 0.

Example 1
Input:
48 
Output:
68

Example 2
Input:
15
Output:
35
*/

class Solution {
public:
    int smallestFactorization(int a) {
        if (a < 2)
            return a;
        long l = 0;
        for (int i = 9, d = 0; i >= 2 && d < 10; i--) {
            while (a % i == 0 && d < 10) {
                l += i * pow(10, d++);
                a /= i;
            }
        }
        return (a > 1 || l > INT_MAX) ? 0 : l;
    }
};

class Solution {
public:
    int smallestFactorization(int a) {
        if (a < 2)
            return a;
        string s(10, '0');  // only collect 10 digit, for INT_MAX is 10 digit;
        for (int i = 9, d = 9; i >= 2 && d; i--) {
            while (a % i == 0 && d) {
                s[d--] = '0' + i;
                a /= i;
            }
        }
        return (a > 1 || stol(s) > INT_MAX) ? 0 : stoi(s);
    }
};

class Solution {
public:
    int smallestFactorization(int a) {
        if (a < 2)
            return a;
        string s;
        for (int i = 9; i >= 2; i--) {
            while (a % i == 0) {
                s.insert(s.begin(), ('0' + i));
                a /= i;
            }
        }
        return (a > 1 || s.size() > 10 || stol(s) > INT_MAX) ? 0 : stoi(s);
    }
};
