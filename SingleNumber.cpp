/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int rtn = 0;
        for(int i=0; i<n; i++){
            rtn = rtn^A[i];
        }
        return rtn;
    }
};
