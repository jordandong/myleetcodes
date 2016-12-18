/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int N = nums.size();
        if (N == 0)
            return 0;
        int res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                res += hammingDistance(nums[i], nums[j]);
            }
        }
        return res;
    }
    
    int hammingDistance(int x, int y) {
        int hamming = x ^ y;
        int res = 0;
        while (hamming) {
            res++;
            hamming &= (hamming - 1);
        }
        return res;
    }
};
