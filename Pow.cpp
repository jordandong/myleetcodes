//============================================================================
// Pow(x, n)
// Implement pow(x, n).
//============================================================================



class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool flag = false;
        if(n<0){
            flag=true;
            n=-n;
        }
        
        double res = 1;
        while(n>0){
            if(n%2==1)
                res*=x;
            n/=2;
            x*=x;
        }
        
        if(flag)
            return 1/res;
        else
            return res;
    }
};





class Solution {
public:
    double pow(double x, int n) {
        int sign = 1;
        if (n < 0) 
        	sign = -sign, n = -n;
        double tmp = x, res = 1.0;
        for (int t = n; t > 0; t /= 2) {
            if(t % 2 == 1)
            	res *= tmp;
            tmp = tmp * tmp;
        }
        if (sign < 0)
        	return 1.0 / res;
        return res;
    }
};

int main() {
    return 0;
}
