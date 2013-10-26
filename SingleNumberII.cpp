/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int map[32];
        for(int i=0; i<32; i++)
            map[i] = 0;
        for(int j=0; j<n; j++){
            int pos = 0;
            while(pos<32) {
                if(1&(A[j]>>pos))
                    map[pos]++;
                pos++;    
            }
        }
        int rtn = 0;
        for(int k=0; k<32; k++){
            if(map[k]%3)
              rtn=rtn^(1<<k);
        }
        return rtn;
    }
};
