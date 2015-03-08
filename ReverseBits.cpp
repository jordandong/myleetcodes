/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Tags Bit Manipulation
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i = 0;
        int j = 31;
        while(i < j){
            uint32_t d = ((n>>i) & 1) ^ ((n>>j) & 1);
            if(d){
                n ^= (1<<i);
                n ^= (1<<j);
            }
            i++;
            j--;
        }
        return n;
    }
};
