/*
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
Example1:
a = 2
b = [3]
Result: 8

Example2:
a = 2
b = [1,0]
Result: 1024

Credits:
Special thanks to @Stomach_ache for adding this problem and creating all test cases.

Hide Tags Math
Hide Similar Problems (M) Pow(x, n)
*/

class Solution {
private:
    const int base = 1337;
    int powmod(int a, int k) {
        //a^k mod 1337 where 0 <= k <= 10
        a %= base;
        int result = 1;
        for (int i = 0; i < k; ++i)
            result = (result * a) % base;
        return result;
    }
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty())
            return 1;
        int last_digit = b.back();
        b.pop_back();
        return (powmod(superPow(a, b), 10) * powmod(a, last_digit)) % base;
    }
};

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int result = 1;
        for (const auto& digit : b) {
            result = myPow(result, 10, 1337) * myPow(a, digit, 1337) % 1337;
        }
        return result;
    }

private:
    int myPow(int a, int n, int b) {
        int result = 1;
        int x = a % b;
        while (n) {
            if (n & 1) {
                result = result * x % b;
            }
            n >>= 1;
            x = x * x % b;
        }
        return result % b;
    }
};
