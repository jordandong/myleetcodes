/*
Given a non-empty integer array, find the minimum number of moves required to make all array elements equal,
where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:
Input:
[1,2,3]
Output:
2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

Hide Tags Math
*/

//T : O(NlogN), S : O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int N = nums.size();
        if (N == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int mid = nums[N/2];
        long long res = 0;
        for (auto &e : nums)
            res += abs(e - mid);
        return (int)res;
    }
};

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int N = nums.size();
        if (N == 0)
            return 0;
        sort(nums.begin(), nums.end());
        long long res = 0;
        int i = 0, j = N - 1;
        while (i < j)
            res += (nums[j--] - nums[i++]);
        return (int)res;
    }
};

//T : O(N), S : O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int N = nums.size();
        if (N == 0)
            return 0;
        
        int mid = findKthLargest(nums, (N + 1)/2);
        long long res = 0;
        for (auto &e : nums)
            res += abs(e - mid);
        return (int)res;
    }
    
private:
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
        return -1;
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
