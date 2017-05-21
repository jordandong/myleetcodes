/*
Given a string representing an expression of fraction addition and subtraction, you need to return the calculation result in string format.
The final result should be irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of fraction that has denominator 1.
So in this case, 2 should be converted to 2/1.

Example 1:
Input:"-1/2+1/2"
Output: "0/1"

Example 2:
Input:"-1/2+1/2+1/3"
Output: "1/3"

Example 3:
Input:"1/3-1/2"
Output: "-1/6"

Example 4:
Input:"5/3+1/3"
Output: "2/1"

Note:
1. The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
2. Each fraction (input and output) has format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
3. The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1,10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
4. The number of given fractions will be in the range [1,10].
5. The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.

Hide Tags Math
*/

class Solution {
public:
    string fractionAddition(string expression) {
        int n = 0, d = 1, p = 0, p1 = 0, p2 = 0;
        string s;
        if (expression[0] != '-')
            s = "+" + expression;
        else
            s = expression;

        while (p < s.size()) { //p is current +/-
            for (p1 = p + 1; s[p1] != '/'; ++p1); //p1 is /
            for (p2 = p1 + 1; p2 < s.size() && s[p2] != '+' && s[p2] != '-'; ++p2); //p2 is next +/-
            auto nn = stoi(s.substr(p + 1, p1 - p - 1));
            auto dd = stoi(s.substr(p1 + 1, p2 - p1 - 1));
            auto gcd = GCD(d, dd);
            n = n * dd / gcd + (s[p] == '-' ? -1 : 1) * nn * d / gcd;
            d *= dd / gcd;
            p = p2;
        }
        auto gcd = GCD(abs(n), d);
        return to_string(n / gcd) + "/" + to_string(d / gcd);
    }
private:
    int GCD(int a, int b ){
        return (b == 0) ? a : GCD(b, a % b);
    }
};
