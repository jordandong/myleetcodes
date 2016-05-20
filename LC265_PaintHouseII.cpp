/*
There are a row of n houses, each house can be painted with one of the k colors.
The cost of painting each house with a certain color is different.
You have to paint all the houses such that no two adjacent houses have the same color.
The cost of painting each house with a certain color is represented by a (n x k) cost matrix.
For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2,and so on...
Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
*/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0)
            return 0;
        int k = costs[0].size();
            if(k == 1)
        return costs[0][0];

        vector<int> dp(k, 0);
        int min1, min2;

        for (int i = 0; i < n; ++i){
            int min1_old = (i == 0) ? 0 : min1;
            int min2_old = (i == 0) ? 0 : min2;
            min1 = INT_MAX;
            min2 = INT_MAX;
            for (int j = 0; j < k; ++j){
                if (dp[j] != min1_old || min1_old == min2_old) { //i - 1 painted with color j
                    dp[j] = min1_old + costs[i][j];
                } else {//min1_old occurred when painting house i-1 with color j, so it cannot be added to dp[j]
                    dp[j] = min2_old + costs[i][j];
                }

                if (min1 <= dp[j]) {
                    min2 = min(min2, dp[j]);
                } else {
                    min2 = min1;
                    min1 = dp[j];
                }
            }
        }
        return min1;
    }
};

class Solution {
public:
    int minCostII(vector<vector<int> >& costs) {
        // Write your code here
        int N = costs.size();
        if (N == 0)
            return 0;
        int K = costs[0].size();
        if (K <= 0)
            return 0;

        vector<int> dp(K, 0);
        int m_color = -1, m1 = INT_MAX, m2 = INT_MAX;
        int p_color = -1, p_m1 = 0, p_m2 = 0;
        for (int i = 0; i < N;++i) {
            m_color = -1, m1 = INT_MAX, m2 = INT_MAX;
            for (int c = 0; c < K; c++) {
                //the min cost at i with color c is the cost of painting color c plus the min cost in previous setp at i - 1
                //if at i - 1, the color is the same using second min value, otherwise using the first min value
                dp[c] = costs[i][c] + (p_color == c ? p_m2 : p_m1);
                m2 = min(dp[c], m2); //update the second min value
                if (dp[c] <= m1) {
                    m_color = c; //record the first min value's color
                    m2 = m1; //update second min value
                    m1 = dp[c]; //update the first min value
                }
            }
            p_color = m_color;
            p_m1 = m1;
            p_m2 = m2;
        }
        return m1;
    }
};
