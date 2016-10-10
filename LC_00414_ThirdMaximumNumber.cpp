/*
Given an array of integers, return the 3rd Maximum Number in this array, if it doesn't exist, return the Maximum Number.
The time complexity must be O(n) or less.
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
