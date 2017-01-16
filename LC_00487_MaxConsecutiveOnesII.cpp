/*
Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

Example 1:
Input: [1,0,1,1,0]
Output: 4
Explanation:
Flip the first zero will get the the maximum number of consecutive 1s.
After flipping, the maximum number of consecutive 1s is 4.

Note:
The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res1 = 0, res2 = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                res1 = res2;
                res2 = 0;
            } else {
                res2 += 1;
            }
            ans = max(res1 + res2, ans);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums = {1,1,0,1,1,0,1,1,1};
    cout<<s.findMaxConsecutiveOnes(nums)<<endl;
    return 0;
}
