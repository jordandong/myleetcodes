/*
We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?

Note that our partition must use every number in A, and that scores are not necessarily integers.

Example:
Input: 
A = [9,1,2,3,9]
K = 3
Output: 20
Explanation: 
The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned A into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
 

Note:

1 <= A.length <= 100.
1 <= A[i] <= 10000.
1 <= K <= A.length.
Answers within 10^-6 of the correct answer will be accepted as correct.
*/

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int N = A.size();
        vector<int> S = {0};
        vector<vector<double>> dp(K + 1, vector<double>(N + 1, 0));
        for (int i = 0; i < N; i++)
            S.push_back(S.back() + A[i]);
        for (int k = 1; k <= K; k++) {
            for (int i = k; i <= N; i++) {
                if (k == 1) {
                    dp[k][i] = (double)S[i] / i;
                } else { 
                    //ending with j elements, last avg is from i to j elements
                    //make sure first i - 1 elements is at least k - 1 > 0 group
                    for (int j = i; j <= N; j++) { 
                        dp[k][j] = max(dp[k][j], dp[k - 1][i - 1] + (double)(S[j] - S[i - 1])/(j - i + 1));
                    }
                }
            }
        }
        return dp[K][N];
    }
};
