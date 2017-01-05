/*
Find the largest palindrome made from the product of two n-digit numbers.

Since the result could be very large, you should return the largest palindrome mod 1337.

Example:

Input: 2

Output: 987

Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

Note:

The range of n is [1,8].

Subscribe to see which companies asked this question

Have you met this question in a real interview? Yes  
*/

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1)
            return 9;

        long maxNum = pow(10, n) - 1;
        long possibleNum = maxNum * maxNum;
    
        long divider = pow(10, n);
        long left = possibleNum / divider;   //Find the left part
        long right = possibleNum % divider; //Find the right part
    
        if (left == reverts(right))// if they are palindrome
            return possibleNum % 1337;
    
        /* Example: if number is 9869, then the possibleNum can only be 9779,
                    if number is 9379, then the possibleNum can be 9339, 
                    so the left part number is determined by the function below
        */
        
        if (reverts(left) > right)
            left--;
    
        possibleNum = left * divider + reverts(left);

        while (left >= divider / 10) { // left should be no smaller than pow(10, n-1)
            for (long i = maxNum; i * i > possibleNum; i--) {
                if (possibleNum % i == 0)
                    return possibleNum % 1337;
            }
            left--;
            possibleNum = left * divider + reverts(left);
        }

        return possibleNum % 1337;
    }

private:
    long reverts(long right) {
        long result = 0;
        while(right != 0) {
            result = 10*result + right%10;
            right /= 10;
        }
        return result;
    }
};
