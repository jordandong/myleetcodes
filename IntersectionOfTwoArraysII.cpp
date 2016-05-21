/*
Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Follow up:
1. What if the given array is already sorted? How would you optimize your algorithm?
2. What if nums1's size is small compared to num2's size? Which algorithm is better?
3. What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

Hide Tags Binary Search Hash Table Two Pointers Sort
*/

//T : O(N) , S : O(N)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> res;
        for (auto &e : nums1)
            mp[e]++;
        for (auto &e : nums2) {
            if (mp[e]-- > 0)
                res.push_back(e);
        }
        return res;
    }
};

//T : O(NlogN) , S : O(1)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        int i = 0, j = 0;
        vector <int> res;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < N1 && j < N2) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};
