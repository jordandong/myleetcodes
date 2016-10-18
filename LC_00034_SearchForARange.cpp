/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

Hide Tags Array Binary Search
*/

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2, -1);
        int start = -1;
        int lo = 0;
        int hi = n - 1;
        while(lo < hi){//find left index
            int mid = lo + (hi - lo)/2;
            if(A[mid] < target){
                lo = mid+1;
            }else{
                hi=mid;
            }
        }
        if(A[lo] == target)
            start = lo;
        else
            return res;
            
        lo = start;
        hi = n - 1;
        while(lo < hi){//find right index
            int mid = lo + (hi - lo + 1)/2; //make sure the mid is always the bigger one when even
            if(target < A[mid]){
                hi = mid-1;
            }else{
                lo = mid;
            }
        }
        res[0]= start;
        res[1] = lo;
        return res;
    }
};
