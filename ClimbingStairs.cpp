//============================================================================
// You are climbing a stair case. It takes n steps to reach to the top.
//
// Each time you can either climb 1 or 2 steps.
// In how many distinct ways can you climb to the top?
//============================================================================

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
        	return n;
        int a = 1;
        int b = 2;
        int c;
        for (int i = 2; i < n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main() {
    return 0;
}


class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *arr = new int[n+1];
        for(int i=0;i<=n;i++)
            arr[i]=0;
        return climb(n, arr);
    }
    
    int climb(int n, int *arr) {
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        
        if(arr[n]>0)
            return arr[n];
            
        arr[n] = climb(n-1, arr) + climb(n-2, arr);
        return arr[n];
    }
};
