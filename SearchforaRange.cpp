//============================================================================
// Search for a Range
// Given a sorted array of integers, find the starting and ending position of
// a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].
//============================================================================

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int start = -1;
        int lo = 0;
        int hi = n-1;
        while(lo<hi){//find left index
            int mid = lo + (hi-lo)/2;
            if(A[mid]<target){
                lo=mid+1;
            }else{
                hi=mid;
            }
        }
        if(A[lo]==target)
            start=lo;
        else
            return vector<int>(2, -1);
            
        lo=start;
        hi=n-1;
        while(lo<hi){//find right index
            int mid = lo + (hi-lo+1)/2; //make sure the mid is always the bigger one when even
            if(target<A[mid]){
                hi=mid-1;
            }else{
                lo=mid;
            }
        }
        vector<int> res;
        res.push_back(start);
        res.push_back(lo);
        return res;
        
    }
};




class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        
        int a = BSTa(A, 0, n-1, n, target);
        int b = BSTb(A, 0, n-1, n, target);
        if(a<0){
            res.push_back(a);
            res.push_back(a);
        }else{
            res.push_back(a);
            res.push_back(b);
        }
        return res; 
    }
    
    int BSTa(int *A, int n1, int n2, int n, int target){
        if(n1>n2)
            return -1;
            
        int mid=(n1+n2)/2;
            
        if(A[mid]>target)
            return BSTa(A, n1, mid-1, n, target);
        else if(A[mid]<target)
            return BSTa(A, mid+1, n2, n, target);
        else if(A[mid]==target){
            if(mid==0||A[mid-1]<A[mid])
                return mid;
            else
                return BSTa(A, 0, mid-1, n, target);
        }
    }
    
    int BSTb(int *A, int n1, int n2, int n, int target){
        if(n1>n2)
            return -1;
            
        int mid=(n1+n2)/2;
            
        if(A[mid]>target)
            return BSTb(A, n1, mid-1, n, target);
        else if(A[mid]<target)
            return BSTb(A, mid+1, n2, n, target);
        else if(A[mid]==target){
            if(mid==n-1||A[mid]<A[mid+1])
                return mid;
            else
                return BSTb(A, mid+1, n-1, n, target);
        }
    }
};



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l = lower_bound(A, A + n, target) - A;
        int u = upper_bound(A, A + n, target) - A - 1;
        vector<int> res(2, -1);
        if (l > u)
        	return res;
        res[0] = l;
        res[1] = u;
        return res;
    }
};

int main() {
	return 0;
}
