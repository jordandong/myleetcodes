/*
You are given an array of positive and negative integers. If a number n at an index is positive, then move forward n steps.
Conversely, if it's negative (-n), move backward n steps.
Assume the first element of the array is forward next to the last element, and the last element is backward next to the first element.

Determine if there is a loop in this array.
A loop starts and ends at a particular index with more than 1 element along the loop.
The loop must be "forward" or "backward'.

Example 1: Given the array [2, -1, 1, 2, 2], there is a loop, from index 0 -> 2 -> 3 -> 0.
Example 2: Given the array [-1, 2], there is no loop.
Example 3: Given the array [2, 0, 2, 1, 3], return false since 0 is not supposed to appear in the array.

Can you do it in O(n) time complexity and O(1) space complexity?
*/

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int N = nums.size();
        if (N == 0)
            return false;
        for (auto &e : nums)
            if (e == 0)
                return false;
        
        for (int i = 0; i < N; i++) {
            if (nums[i] == 0)
                continue;
            int slow = i, fast = i, d = getDirection(nums[i]);
            while ((getDirection(nums[fast]) == d) &&
                   (getDirection(nums[getNextIdx(fast, nums)]) == d)) {
                slow = getNextIdx(slow, nums);
                fast = getNextIdx(fast, nums);
                fast = getNextIdx(fast, nums);
                if (slow == fast) { //meet, there is a circle
                    if (abs(nums[fast]) == N) //one element
                        break;
                    return true;
                }
            }
        
            // no loop on this path
            //nums[i] = 0; //option 1 : set start point to zero
            slow = i; //option 2 : set all element on the path to zero
            while (getDirection(nums[slow]) == d) {
                fast  = getNextIdx(slow, nums);
                nums[slow] = 0;
                slow = fast;
            }
        }
        return false;      
    }
private:
    int UP = 0, DOWN = 1, EQUAL = 2;

    int getNextIdx(int idx, vector<int> &nums) {
        idx += nums[idx];
        return (idx + nums.size()) % nums.size();
    }

    int getDirection(int val) {
        return val > 0 ? UP : (val < 0 ? DOWN : EQUAL);
    }
};
