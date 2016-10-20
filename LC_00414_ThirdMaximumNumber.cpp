/*
Given an array of integers, return the 3rd Maximum Number in this array, if it doesn't exist, return the Maximum Number.
The time complexity must be O(n) or less.
Given a non-empty array of integers, return the third maximum number in this array.
If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]
Output: 1
Explanation: The third maximum is 1.

Example 2:
Input: [1, 2]
Output: 2
Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

Example 3:
Input: [2, 2, 3, 1]
Output: 1
Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

Hide Tags Array
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int N = nums.size();
        int cnt = 0;
        vector<long> top(3, INT_MIN);
        top[0] -= 1;
        top[1] -= 1;
        top[2] -= 1;
        for (int i = 0; i < N; i++) {
            if (nums[i] > top[2] && nums[i] != top[1] && nums[i] != top[0]) {
                top[2] = nums[i];
                if (top[2] > top[1])
                    swap(top[2], top[1]);
                if (top[1] > top[0])
                    swap(top[1], top[0]);
                cnt++;
            }
        }
        if (cnt < 3)
            return top[0];
        return top[2];
    }
};
