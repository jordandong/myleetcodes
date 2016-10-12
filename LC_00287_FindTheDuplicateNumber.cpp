/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate element must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
1. You must not modify the array (assume the array is read only).
2. You must use only constant extra space.
3. Your runtime complexity should be less than O(N^2).

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Hide Tags Array Two Pointers Binary Search
*/


//T : O(N) , S : O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums.size() - 1;
        int fast = slow;
        //Similar to finding the duplicated element in linked list with a circle
        do {
            slow = nums[slow] - 1;
            fast = nums[fast] - 1;
            fast = nums[fast] - 1;
        } while (slow != fast); //met if there is a circle
        
        fast = nums.size() - 1; //reset one pointer to the begining
        while (slow != fast) { //find the duplicated location
            slow = nums[slow] - 1;
            fast = nums[fast] - 1;
        }
        return slow + 1;
    }
};
