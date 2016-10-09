/*
Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:
1. The length of both num1 and num2 is < 5100.
2. Both num1 and num2 contains only digits 0-9.
3. Both num1 and num2 does not contain any leading zero.
4. You must not use any built-in BigInteger library or convert the inputs to integer directly.

Hide Tags Math
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        string res = "";
        int carry = 0;
        while (n1 || n2) {
            int v1 = 0, v2 = 0;
            if (n1) {
                v1 = (num1[--n1] - '0'); 
            }
            
            if (n2) {
                v2 = (num2[--n2] - '0'); 
            }
            int v =  v1 + v2 + carry;
            carry = v/10;
            v %= 10;
            string s(1, '0' + v);
            res = s + res;
        }
        return carry ? "1" + res : (res == "" ? "0" : res);
    }
};
