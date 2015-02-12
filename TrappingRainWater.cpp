/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Hide Tags Array Stack Two Pointers
*/

class Solution {
public:
    int trap(int A[], int n) {
        if(n <= 2)
            return 0;
        int lmax[n];
        int rmax;
        int total = 0;
        lmax[0] = A[0];
        for (int i = 1; i < n; i++)
            lmax[i] = max(lmax[i-1], A[i]);

        rmax = A[n-1];
        for (int i = n - 1; i >= 0; i--){
            rmax = max(rmax, A[i]);
            total += (min(lmax[i], rmax) - A[i]) ;
        }
        return total;
    }
};

class Solution {
public:
    int trap(int A[], int n) {
        vector<int> left(n, 0);
        int total = 0;
        int max = 0;
        for(int i = 0; i < n; i++){
            if(A[i] < max){
                left[i] = max - A[i];
            }else{
                max = A[i];
            }
        }
        
        max = 0;
        for(int i = n-1; i >= 0; i--){
            if(A[i] < max){
                total += min(left[i], max - A[i]);
            }else{
                max = A[i];
            }
        }
        return total;
    }
};
