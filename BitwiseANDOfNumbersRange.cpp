/8
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.

Hide Tags Bit Manipulation
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int N = 31;
        int res = 0;
        while(N >= 0){     
            if(((m>>N) & 0x1) ^ ((n>>N) & 0x1))//check from the highest bits, if different, stop, if equal, set this bits in res
                return res;
            res |= (0x1<<N & m);
            N--;
        }
        return res;  
    }
};
