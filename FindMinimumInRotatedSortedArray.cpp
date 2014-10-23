/*
 *Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *Find the minimum element.
 *You may assume no duplicate exists in the array.
 */
 
class Solution {
public:
    int findMin(vector<int> &num) {
        int lo = 0;
        int hi = num.size()-1;
        int mid = -1;
        while(lo < hi){
            mid = lo + (hi-lo)/2;
            if(num[mid] >num[hi])
                lo = mid + 1;
            else if(num[mid] < num[hi])
                hi = mid;
        }
        return num[lo];
    }
};
 
class Solution {
public:
    int findMin(vector<int> &num) {
        int lo = 0;
        int hi = num.size()-1;
        int mid = -1;
        while(lo < hi){
            mid = lo + (hi-lo+1)/2;
            if(num[mid] >num[hi])
                lo = mid + 1;
            else if(num[mid] < num[hi])
                hi = mid;
            else
                return min(num[lo], num[hi]);
        }
        return num[lo];
    }
};


