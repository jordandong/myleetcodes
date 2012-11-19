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
