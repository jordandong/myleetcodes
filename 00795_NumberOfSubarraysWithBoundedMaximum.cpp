/*
We are given an array A of positive integers, and two positive integers L and R (L <= R).

Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least L and at most R.

Example :
Input: 
A = [2, 1, 4, 3]
L = 2
R = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
Note:

L, R  and A[i] will be an integer in the range [0, 10^9].
The length of A will be in the range of [1, 50000].
*/

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int res = 0, routes = 0, starts = 0;
        for (int val : A) {
            if (L <= val && val <= R) {
                // when val is in range, all the before less than L nodes becomes routes
                routes +=  starts + 1;
                starts = 0;
                res += routes;
            } else if (val < L) {
                // val < L, all routes could expand and this val becomes new potential start  
                res += routes;
                starts++;
            } else {
                //reset , invaild node
                routes = 0;
                starts = 0;
            }
        }
        return res;
    }
};
