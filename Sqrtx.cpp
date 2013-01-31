//============================================================================
// Sqrt(x)
// Implement int sqrt(int x).
//
// Compute and return the square root of x.
//============================================================================

class Solution {
public:
    int sqrt(int x) {
        if(x < 2)
            return x;
        long int l = 0;
        long int u = 1 + (x / 2);
        while(l +1 < u) {
            long long m = l + (u - l) / 2;
            long long p = m * m;
            if(p > x)
                u = m;
            else if(p < x)
                l = m;
            else
                return m;
        }
        return l;
    }
};

#include <iostream>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if(x < 2)
        	return x;
        long long l = 0;
        long long u = 1 + (x / 2);
        while(l +1 < u) {
            long long m = l + (u - l) / 2;
            long long p = m * m;
            if(p > x)
                u = m;
            else if(p < x)
                l = m;
            else
                return m;
        }
        return (int)l;
    }
};

int main() {
	return 0;
}

class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long l = 0;
        long long r = x;
        long long ret = 0;
        while(l <= r){
            long long mid = l + (r - l)/2;
            long long result = mid * mid;
            if(result == x){
                ret = mid;
                return (int)ret;
            }else if(result < x){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return (int)r;
    }
};
