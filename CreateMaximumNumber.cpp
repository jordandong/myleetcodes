/*
Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.

Example 1:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]

Example 2:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]

Example 3:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
return [9, 8, 9]

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Tags Dynamic Programming Greedy
*/

//T : O(K*(m + n)^2) S : O(m + n)
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> res;
        for (int k1 = max(k - n2, 0); k1 <= min(k, n1); ++k1) { //O(k)
            vector<int> res1 = maxNumberHelper1(nums1, k1); //O(n)
            vector<int> res2 = maxNumberHelper1(nums2, k - k1); //O(m)
            res = max(res, maxNumberHelper2(res1, res2)); //O((m + n)^2)
        }
        return res;
    }

    vector<int> maxNumberHelper1(vector<int> &nums, int k) {
        int drop = nums.size() - k;
        vector<int> res;
        for (int num : nums) {
            while (drop && res.size() && res.back() < num) {
                res.pop_back();
                drop--;
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }

    //O ((m+n)^2)
    vector<int> maxNumberHelper2(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        auto i1 = nums1.begin(), end1 = nums1.end();
        auto i2 = nums2.begin(), end2 = nums2.end();
        while (i1 != end1 || i2 != end2) {
            res.push_back(vector<int>(i1, end1) > vector<int>(i2, end2) ? *i1++ : *i2++);
        }
        return res;
    }
};
