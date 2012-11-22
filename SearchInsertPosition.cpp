//============================================================================
// Search Insert Position
//
// Given a sorted array and a target value, return the index if the target is
// found. If not, return the index where it would be if it were inserted in order.
//
// You may assume no duplicates in the array.
//
// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0
//============================================================================

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start=0, end=n-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(A[mid]==target)
                return mid;
            if(target>A[mid])
                start=mid+1;
            else
                end = mid-1;
        }
        return start;
    }
};


#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int l = 0;
        int u = n - 1;
        while (l <= u) {
            int m = l + (u - l) / 2;
            if (A[m] > target)
            	u = m - 1;
            else if (A[m] < target)
            	l = m + 1;
            else
            	return m;
        }
        return l;
    }
};

int main() {
    return 0;
}
