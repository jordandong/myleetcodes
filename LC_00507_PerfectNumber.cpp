/*
We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.

Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14

Note: The input number n will not exceed 100,000,000. (1e8)

Hide Tags Math
*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        return num == 6 || num == 28 || num == 496 || num == 8128 || num == 33550336;
    }
};

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1)
            return false;

        int sum = 0;
        for (int i = 1; i <= num/i; i++) {
            if (num % i == 0) {
                sum += i;
                sum += num/i;
            }
        }
        return (sum - num) == num;
    }
};
