/*
The set S originally contains numbers from 1 to n.
But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error.
Your task is to firstly find the number occurs twice and then find the number that is missing.
Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

Note:
1. The given array size will in the range [2, 10000].
2. The given array's numbers won't have any order.
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
                i--;
            }
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1)
                return {nums[i], i + 1};
        return {};
    }
};

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int N = nums.size(), a = 0, b = 0;
        vector<int> cnt(N, 0);
        for(int i = 0; i < N; i++) {
            if (++cnt[nums[i] - 1] == 2)
                a = nums[i];
            b ^= nums[i];
            b ^= (i + 1);
        }
        b ^= a;
        return {a, b};
    }
};
