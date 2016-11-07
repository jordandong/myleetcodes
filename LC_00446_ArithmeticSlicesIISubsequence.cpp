/*
A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequences:
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9

The following sequence is not arithmetic.
1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A subsequence slice of that array is any sequence of integers (P0, P1, ..., Pk) such that 0 ≤ P0 < P1 < ... < Pk < N.
A subsequence slice (P0, P1, ..., Pk) of array A is called arithmetic if the sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] is arithmetic. In particular, this means that k ≥ 2.
The function should return the number of arithmetic subsequence slices in the array A.
The input contains N integers. Every integer is in the range of -231 and 231-1 and 0 ≤ N ≤ 1000. The output is guaranteed to be less than 2^31-1.

Example:
Input: [2, 4, 6, 8, 10]
Output: 7
Explanation:
All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]

Hide Tags Dynamic Programming
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int N = A.size();
        if (N == 0)
            return 0;
        vector<unordered_map<long long, int >> dp(N);
        unordered_set<int> s(A.begin(), A.end());
        int res = 0;
        for (int i = 1; i < N; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                long long d = (long long)A[i] - A[j];
                int tmp = dp[j].count(d) ? dp[j][d] : 0;
                if (tmp)
                    res += tmp;
                if (s.count(A[i] + d)) //if no further solution, no need to store this last information
                    dp[i][d] += (1 + tmp);
            }
        }
        return res;
    }
};


//MLE or TLE
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans = 0;
        int N = A.size();
        if (N < 3)
            return 0;
        vector<unordered_map<long long, int>> dp(N);
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                long long dist = (long long)A[i] - A[j];
                auto it = dp[j].find(dist);
                int s = (it == dp[j].end() ? 0 : it->second) + 1;
                dp[i][dist] += s;
                ans += s;
            }
            ans -= i;
        }
        return ans;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int result = 0;
        vector<unordered_map<long long, int>> dp(A.size());
        for (int i = 1; i < A.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                const auto diff = static_cast<long long>(A[i]) - A[j];
                ++dp[i][diff];
                if (dp[j].count(diff)) {
                    dp[i][diff] += dp[j][diff];
                    result += dp[j][diff];
                }
            }
        }
        return result;
    }
};
