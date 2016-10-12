/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Hide Tags
Divide and Conquer Heap
*/

//T:O(N)~O(N^2) S:O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int N = nums.size();
        if (N == 0 || k <= 0)
            return -1;
        int lo = 0, hi = N - 1;
        while (lo <= hi) {
            int p = partition(nums, lo, hi);
            if (p + 1 > k) {
                hi = p - 1;
            } else if(p + 1 < k) {
                lo = p + 1;
            } else {
                return nums[p];
            }
        }
    }
    
    int partition(vector<int>& nums, int lo, int hi) {
        int j = hi - 1;
        while (lo <= j) {
            if(nums[lo] < nums[hi])
                swap(nums[lo], nums[j--]);
            else
                lo++;
        }
        swap(nums[lo], nums[hi]);
        return lo;
    }
};

//T:O(Nlogk) S:O(k)
class min_heap{
public:    
    bool operator() (int &a, int &b) {
        return a > b;    
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int N = nums.size();
        if (N == 0 || k <= 0)
            return -1;
        priority_queue<int, vector<int>, min_heap> mhp;
        for (auto e : nums) {
            mhp.push(e);
            if (mhp.size() > k) 
                mhp.pop();
        }
        return mhp.top();
    }
};

//T:O(NlogN) S:O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int N = nums.size();
        if (N == 0 || k <= 0)
            return -1;
        sort(nums.begin(), nums.end());
        return nums[N - k];
    }
};
