/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Hide Tags Bit Manipulation
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int size = 32;
        int res = 0;
        int cnt[size];
        memset(cnt, 0, sizeof(int)*size);

        for(int i = 0; i < n; i++){
            int shift = 0;
            while(shift < size){
                if(A[i] & (1<<shift))
                    cnt[shift]++;
                shift++;
            }
        }
        
        for(int i = 0; i < size; i++)
            if(cnt[i] % 3)
                res ^= (1<<i);
        return res;
    }
};
