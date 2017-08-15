/*
Given a sorted array, two integers k and x, find the k closest elements to x in the array. 
The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]

Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]

Note:
1. The value k is positive and will always be smaller than the length of the sorted array.
2. Length of the given array is positive and will not exceed 10^4
3. Absolute value of elements in the array and x will not exceed 10^4
*/

//T: O(N)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = arr.size() - 1;
        while (i - k >= 0 && abs(x - arr[i - k]) <= abs(x - arr[i]))
            i--;
        return {arr.begin() + i - k + 1, arr.begin() + i + 1};
    }
};

// T: O(logN)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
	    int lo = 0, hi = arr.size() - k;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (x - arr[mid] > arr[mid + k] - x)
                lo = mid + 1;
            else
                hi = mid;
        }
        return {arr.begin() + lo, arr.begin() + lo + k};
    }
};
