//T : O(K*(m + n)) S : O(m + n)
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> res;
        for (int k1 = max(k - n2, 0); k1 <= min(k, n1); ++k1) { //O(k)
            vector<int> res1 = maxNumberHelper1(nums1, k1); //O(n)
            vector<int> res2 = maxNumberHelper1(nums2, k - k1); //O(m)
            res = max(res, maxNumberHelper2(res1, res2)); //O(m + n)
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
