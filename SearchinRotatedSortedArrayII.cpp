/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Hide Tags Array Binary Search
*/

class Solution {
public:
    bool search(int A[], int n, int target) {
        int lo = 0;
        int hi = n-1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(A[mid] == target)
                return true;
            if(A[lo] < A[mid]){
                if(A[lo] <= target && target < A[mid]){
                    hi = mid - 1;
                }else{
                    lo = mid + 1;
                }
            }else if(A[mid] < A[lo]){
                if(A[mid] < target && target <= A[hi]){
                    lo = mid + 1;
                }else{
                    hi = mid - 1;
                }
            }else{
                lo++;
            }
        }
        return false;
    }
};
