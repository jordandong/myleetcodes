/*
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

Note: n will be less than 15,000.

Example 1:
Input: [1, 2, 3, 4]

Output: False

Explanation: There is no 132 pattern in the sequence.
Example 2:
Input: [3, 1, 4, 2]

Output: True

Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:
Input: [-1, 3, 2, 0]

Output: True

Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
*/

//T : O(N ^ 2), S : O(1)
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int N = nums.size();
        if (N < 3)
            return false;
        int mi = nums[0];
        for (int j = 1; j < N; j++) {
            mi = min(nums[j], mi);
            if (mi == nums[j])
                continue;
            for (int k = j + 1; k < N; k++) {
                if (mi < nums[k] && nums[k] < nums[j])
                    return true;
            }
        }
        return false;
    }
};
