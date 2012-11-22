//============================================================================
// Search in Rotated Sorted Array
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
// You are given a target value to search. If found in the array return its
// index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//============================================================================

class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return RSA(A, 0, n-1, target);
    }
    
    int RSA(int *A, int start, int end, int target){
        if(start>end)
            return -1;
        int mid = (start+end)/2;
        
        if(target==A[mid])
            return mid;
        if(target==A[start])
            return start;
        if(target==A[end])
            return end;
        
        if(A[mid]>A[start]){
            if(target>A[start]){
                if(target>A[mid])
                    return RSA(A,mid+1, end, target);
                else
                    return RSA(A,start, mid-1, target);
            }
            else{
                return RSA(A,mid+1, end, target);
            }
        }else{
            if(target>A[start]){
                return RSA(A,start, mid-1, target);
            }
            else{
                if(target<A[mid])
                    return RSA(A,start, mid-1, target);
                else
                    return RSA(A,mid+1, end, target);
            }
        }
    }
};

#include <iostream>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0, u = n - 1;
        while (l <= u) {
            int m = l + (u - l) / 2;
            if (A[m] == target)
            	return m;
            if (A[m] >= A[l]) {
                if (A[l] <= target && target < A[m])
                	u = m - 1;
                else
                	l = m + 1;
            }
            else {
                if (A[m] < target && target <= A[u])
                	l = m + 1;
                else
                	u = m - 1;
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}
