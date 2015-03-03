/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Tags Array Binary Search
*/

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int lo = 0;
        int hi = num.size()-1;
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            if(lo == mid)
                return num[lo]>num[hi] ? lo : hi; 
            
            if(mid - 1 >= 0 && num[mid - 1] > num[mid]){
                hi = mid -1;
                continue;
            }
            if(mid + 1 < num.size() && num[mid + 1]> num[mid] ){
                lo = mid +1;
                continue;
            }
            return mid;
        }
        return lo;
    }
};
