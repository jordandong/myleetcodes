/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:
You may assume that the array does not change.
There are many calls to sumRange function.

Hide Tags Dynamic Programming
*/

class NumArray {
public:
    NumArray(vector<int> &nums) {
        data.push_back(0);
        for(auto &e : nums)
            data.push_back(data.back() + e);
    }

    int sumRange(int i, int j) {
        return data[j + 1] - data[i];
    }
private:
    vector<long long> data;
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
