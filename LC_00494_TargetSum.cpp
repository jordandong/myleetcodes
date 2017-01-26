/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S.
Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5

Explanation: 
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
There are 5 ways to assign symbols to make the sum of nums be target 3.

Note:
1. The length of the given array is positive and will not exceed 20.
2. The sum of elements in the given array will not exceed 1000.
3. Your output answer is guaranteed to be fitted in a 32-bit integer.

Hide Tags Depth-first Search Dynamic Programming
*/

/*
                  sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
                       2 * sum(P) = target + sum(nums)
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (auto n : nums)
            sum += n;
        if ((sum + S) & 1 || S > sum || S < -sum)
            return 0;
        int newS = (sum + S) >> 1;
        vector<int> dp(newS + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = newS; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[newS];
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0, sum = 0;
        findTargetSumWaysHelper(nums, sum, S, 0, res);
        return res;
    }

    bool findTargetSumWaysHelper(vector<int>& nums, int &sum, int target, int pos, int &res){
        if (pos == nums.size()){
            if (sum == target)
                return true;
            return false;
        }
        
        sum += nums[pos];
        if (findTargetSumWaysHelper(nums, sum, target, pos + 1, res))
            res++;
        sum -= nums[pos];
    
        sum -=nums[pos];
        if (findTargetSumWaysHelper(nums, sum, target, pos + 1, res))
            res++;
        sum += nums[pos];
    
        return false;
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        findTargetSumWaysHelper(nums, S, true, 0, res);
        findTargetSumWaysHelper(nums, S, false, 0, res);
        return res;
    }
private:
    void findTargetSumWaysHelper(vector<int>& nums, int S, bool add, int idx, int &res) {
        if (idx == nums.size()) {
            return;
        }
        if (add) {
            S -= nums[idx];
        } else {
            S += nums[idx];
        }
        if (S == 0 && idx == nums.size() - 1) {
            res++;
        } else {
            findTargetSumWaysHelper(nums, S, true, idx + 1, res);
            findTargetSumWaysHelper(nums, S, false, idx + 1, res);
        }
    }
};
