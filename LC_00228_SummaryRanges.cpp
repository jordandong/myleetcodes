/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Hide Tags Array
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int N = nums.size();
        if (N == 0)
            return {};
        vector<string> res;
        for (int i = 0; i < N;) {
            int start = i, end = i;
            while (end < N - 1 && nums[end + 1] == nums[end] + 1)
                end++;
            if (start == end) {
                res.push_back(to_string(nums[start]));
            } else {
                res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            }
            i = end + 1;
        }
        return res;
    }
};

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int N = nums.size();
        if (N == 0)
            return {};
        int exp = nums[0];
        int start = nums[0];
        int end = nums[0];
        vector<string> res;
        for (int i = 0; i < N; i++) {
            if (nums[i] == exp) {
                end = nums[i];
                exp++;
            } else {
                if (start == end) {
                    res.push_back(to_string(start));
                } else {
                    res.push_back(to_string(start) + "->" + to_string(end));
                }
                start = nums[i];
                end = nums[i];
                exp = nums[i] + 1;
            }
        }
        if (start == end) {
            res.push_back(to_string(start));
        } else {
            res.push_back(to_string(start) + "->" + to_string(end));
        }
        return res;
    }
};
