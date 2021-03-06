/*
Given an array of scores that are non-negative integers.
Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on.
Each time a player picks a number, that number will not be available for the next player.
This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

Example 1:
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5.
If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return False.

Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7.
No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.

Note:
1. 1 <= length of the array <= 20.
2. Any scores in the given array are non-negative integers and will not exceed 10,000,000.
3. If the scores of both players are equal, then player 1 is still the winner.

Hide Tags Dynamic Programming Minimax
*/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int N = nums.size();
        if (N & 1 == 0)
            return true;
        vector<int> dp(N, INT_MIN);
        for(int i = N - 1; i >= 0; i--) {
            for(int j = i; j < N; j++) {
                if(j == i)
                    dp[j] = nums[i];
                else
                    dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        return dp[N - 1] >= 0;
    }
};

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int N = nums.size();
        if (N & 1 == 0)
            return true;
        vector<vector<int>> dp(N, vector<int> (N, INT_MIN));
        for (int i = 0; i < N; i++)
            dp[i][i] = nums[i];
        for (int len = 1; len < N; len++) {
            for (int i = 0; i < N - len; i++) {
                int j = i + len;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][N - 1] >= 0;
    }
};

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> dp(N, vector<int> (N, INT_MIN));
        if (N & 1)
            return PredictTheWinnerHelper(nums, 0, N - 1, dp) >= 0;
        return true;
    }
private:
    int PredictTheWinnerHelper(vector<int> &nums, int begin, int end, vector<vector<int>> &dp) {
        if (begin == end)
            return nums[begin];
        if (dp[begin][end] == INT_MIN) {
            dp[begin][end] = max(nums[begin] - PredictTheWinnerHelper(nums, begin + 1, end, dp),
                nums[end] - PredictTheWinnerHelper(nums, begin, end -1, dp));
        }
        return dp[begin][end];
    }
};

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.size() & 1)
            return PredictTheWinnerHelper(nums, 0, nums.size() - 1, 0, 0, true);
        return true;
    }
private:
    bool PredictTheWinnerHelper(vector<int> &nums, int begin, int end, int score1, int score2, bool p1) {
        if (begin > end)
            return score1 >= score2;
        if (p1)
            return (PredictTheWinnerHelper(nums, begin + 1, end, score1 + nums[begin], score2, !p1) || 
                    PredictTheWinnerHelper(nums, begin, end - 1, score1 + nums[end], score2, !p1));
        else
            return (PredictTheWinnerHelper(nums, begin + 1, end, score1, score2 + nums[begin], !p1) &&
                    PredictTheWinnerHelper(nums, begin, end - 1, score1, score2 + nums[end], !p1));
    }
};

//[0,0,7,6,5,6,1] is an example of a test case that could fail. The first player cannot force the second player to choose even or odd position always.
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int N = nums.size();
        if (N % 2 == 0)
            return true;
        int sum_odd = 0, sum_even = 0;
        for (int i = 0; i < N; i++) {
            if (i & 1)
                sum_even += nums[i];
            else
                sum_odd += nums[i];
        }
        if (nums[0] >= abs(sum_even - sum_odd + nums[0]) || nums[N - 1] >= abs(sum_even - sum_odd + nums[N - 1]))
            return true;
        return false;
    }
};
