/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Hide Tags Array
*/

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        if(n <= 1 || k == 0)
            return;
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
    
    void reverse(int nums[], int i, int j){
        while(i < j)
            swap(nums[i++], nums[j--]);
    }
};
