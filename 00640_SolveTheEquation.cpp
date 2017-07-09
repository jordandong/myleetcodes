/*
Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.

If there is no solution for the equation, return "No solution".

If there are infinite solutions for the equation, return "Infinite solutions".

If there is exactly one solution for the equation, we ensure that the value of x is an integer.

Example 1:
Input: "x+5-3+x=6+x-2"
Output: "x=2"
Example 2:
Input: "x=x"
Output: "Infinite solutions"
Example 3:
Input: "2x=x"
Output: "x=0"
Example 4:
Input: "2x+3x-6x=x+2"
Output: "x=-1"
Example 5:
Input: "x=x+2"
Output: "No solution"
*/

class Solution {
public:
    string solveEquation(string equation) {
        int last_sign = 1, sec_half = 1;
        int xc = 0, c = 0, val = 0;
        bool has_x = false;
        for (int i = 0 ; i < equation.length(); i++) {
            if (equation[i] == 'x') {
                if (i == 0 || equation[i - 1] < '0' || equation[i - 1] > '9')
                    val = 1;
                xc += val * last_sign * sec_half;
                val = 0;
                has_x = true;
            } else if ('0' <= equation[i] && equation[i] <= '9') {
                val = 10 * val + (equation[i] - '0');
            } else {
                if (!has_x)
                    c += val * last_sign * sec_half;
                
                if (equation[i] == '=') {
                    sec_half = -1;
                    last_sign = 1;
                } else if (equation[i] == '+') {
                    last_sign = 1;
                } else if (equation[i] == '-') {
                    last_sign = -1;
                }
                val = 0;
                has_x = false;
            }
        }
        if (!has_x)
            c += val * last_sign * sec_half;
        
        if (xc == 0) {
            if (c == 0)
                return "Infinite solutions";
            return "No solution";
            
        }
        xc = -c / xc;
        return "x=" + to_string(xc);
    }
};
