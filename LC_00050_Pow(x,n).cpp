/*
Implement pow(x, n).

Hide Tags Math Binary Search
*/

class Solution {
public:
    double pow(double x, int n) {
        double res = 1;
        bool sign = false;
        unsigned int nn;//handle -2147483648
        if(n < 0){
            nn = -n;
            sign = true;
        }else{
            nn = n;
        }
        
        while(nn){
            if(nn & 1)
                res *= x;
            x *= x;
            nn = (nn >> 1);
        }
        return sign ? 1.0/res : res;
    }
};
