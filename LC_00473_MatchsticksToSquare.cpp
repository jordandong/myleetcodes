/*
Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks.
You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick length.
Your output will either be true or false, to represent whether you can save this little girl or not.

Example 1:
Input: [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.

Example 2:
Input: [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.

Note:
1. The length sum of the given matchsticks is in the range of 0 to 10^9.
2. The length of the given matchstick array will not exceed 15.

Hide Tags Depth-first Search
*/

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int SUM = 0, SIDE = 0, N = nums.size();
        for (auto &e : nums)
            SUM += e;
        SIDE = SUM / 4;
        sort(nums.begin(), nums.end());
        if (N < 4 || SUM == 0 || SUM % 4 || SIDE < nums[N - 1])
            return false;
        vector<int> sides(4, SIDE);
        return makesquareHelper(nums, sides, N - 1);
    }

private:
    bool makesquareHelper(vector<int>& nums, vector<int>& sides, int i) {
        if (i < 0) {
            for (auto &e : sides)
                if (e)
                    return false;
            return true;
        }
        for (auto & e : sides) {
            if (nums[i] > e)
                continue;
            e -= nums[i];
            if (makesquareHelper(nums, sides, i - 1))
                return true;
            e += nums[i];
        }
        return false;
    }
};
