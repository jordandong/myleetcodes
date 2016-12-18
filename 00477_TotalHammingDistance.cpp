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
        int res = 0;
        vector<vector<int>> dp(32, vector<int>(2, 0)); //dp[i][j] means ith bit has how many j's
        for (auto &e : nums) {
            for (int i = 0; i < 32; i++) {
                dp[i][(e >> i) & 0x1]++;
                res += dp[i][(e >> i) & 0x1 ^ 0x1];
            }
        }
        return res;
    }
};

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0, N = nums.size();
        for (int i = 0; i < 32; i++) {
            int ones = 0;
            for (auto &e : nums)
                ones += (e >> i) & 0x1;
            res += ones * (N - ones);
        }
        return res;
    }
};
