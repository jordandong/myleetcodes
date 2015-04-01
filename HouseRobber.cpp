/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.

Hide Tags Dynamic Programming
*/

class Solution {
public:
    int rob(vector<int> &num) {
        int sz = num.size();
        if(sz == 0)
            return 0;

        int rob_mx = 0;
        int no_rob_mx = 0;
        for(int i = 0; i < sz; i++){
            int rob_mx_tmp = no_rob_mx + num[i];
            int no_rob_mx_tmp = max(rob_mx, no_rob_mx);
            rob_mx = rob_mx_tmp;
            no_rob_mx = no_rob_mx_tmp;
        }
        return max(rob_mx, no_rob_mx);
    }
};
