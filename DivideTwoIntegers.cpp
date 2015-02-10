/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

Hide Tags Math Binary Search
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = false;
        unsigned int x, y;
        unsigned int res = 0;
        if(dividend < 0) {
            x = -dividend;
            sign = !sign;
        }else{
            x = dividend;
        }
        
        if (divisor < 0) {
            y = -divisor;
            sign = !sign;
        }else{
            y = divisor;
        }
        
        while (x >= y) {
            unsigned int shift = 0;
            unsigned int tmp = y;
            while( ( (unsigned long long)tmp << 1) <= x){
                tmp <<= 1; 
                shift++;
            }
            x -= tmp;
            res |= (1 << shift);
        }

        if(!sign && res > INT_MAX)
            return INT_MAX;
        else
            return sign ? -res : res;
    }
};
