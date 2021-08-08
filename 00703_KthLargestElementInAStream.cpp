/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Returns the element representing the kth largest element in the stream.
 

Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
 

Constraints:

1 <= k <= 104
0 <= nums.length <= 104
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add.
It is guaranteed that there will be at least k elements in the array when you search for the kth element.
*/

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int kIdx = 0;
        K = k;
        cnt = 0;
        while (nums.size() > k && left <= right) {
            int pIndex = partition(nums, left, right);
            if (pIndex == nums.size() - k) {
                kIdx = pIndex;
                break;
            } else if (pIndex < nums.size() - k) {
                left = pIndex + 1;
            } else {
                right = pIndex - 1;
            }
        }
        for (int i = nums.size() - 1; i >= kIdx; i--) {
            data[nums[i]]++;
            cnt++;
        }
    }
    
    int partition(vector<int>& nums, int l, int r) {
        int pValue = nums[r];
        int idx = l;
        for (int i = l; i <= r; i++) {
            if (nums[i] <= pValue) {
                if (i != idx)
                    swap(nums[i], nums[idx]);
                idx++;
            }
        }
        return idx - 1; 
    }
    
    int add(int val) {
        data[val]++;
        if (++cnt > K) {
            auto it = data.begin();
            if (--(it->second) == 0) {
                data.erase(it);
            }
            cnt--;
        }
        return data.begin()->first;
    }
    
    map<int, int> data;
    int K;
    int cnt;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
