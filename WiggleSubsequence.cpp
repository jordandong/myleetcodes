/*
A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative.
A sequence with fewer than two elements is trivially a wiggle sequence.
For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative.
In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence.
A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2

Follow up:
Can you do it in O(n) time?

Credits:
Special thanks to @agave and @StefanPochmann for adding this problem and creating all test cases.

Hide Tags Dynamic Programming Greedy
*/


//T : O(N), S : O(N)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int N = nums.size();
        if (N == 0 || N == 1)
            return N;
        vector<int> diffs;
        for (int i = 0; i + 1 < N; i++)
            diffs.push_back(nums[i + 1] - nums[i]);

        int res = 1;
        int sum = -diffs[0];
        for (int i = 0; i < diffs.size(); i++) {
            if (diffs[i] * sum < 0) {
                sum = 0;
                res += 1;
            }
            sum += diffs[i];
        }
        return res;
    }
};
