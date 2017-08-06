/*
Given an array A (index starts at 1) consisting of N integers: A1, A2, ..., AN and an integer B.
The integer B denotes that from any place (suppose the index is i) in the array A, you can jump to any one of the place in the array A indexed i+1, i+2, …, i+B if this place can be jumped to.
Also, if you step on the index i, you have to pay Ai coins. If Ai is -1, it means you can’t jump to the place indexed i in the array.

Now, you start from the place indexed 1 in the array A, and your aim is to reach the place indexed N using the minimum coins.
You need to return the path of indexes (starting from 1 to N) in the array you should take to get to the place indexed N using minimum coins.

If there are multiple paths with the same cost, return the lexicographically smallest such path.

If it's not possible to reach the place indexed N then you need to return an empty array.

Example 1:
Input: [1,2,4,-1,2], 2
Output: [1,3,5]

Example 2:
Input: [1,2,4,-1,2], 1
Output: []

Note:
1. Path Pa1, Pa2, ..., Pan is lexicographically smaller than Pb1, Pb2, ..., Pbm, if and only if at the first i where Pai and Pbi differ, Pai < Pbi; when no such i exists, then n < m.
2. A1 >= 0. A2, ..., AN (if exist) will in the range of [-1, 100].
3. Length of A is in the range of [1, 1000].
4. B is in the range of [1, 100].
*/

class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        int N = A.size();
        if (N == 0)
            return {};
        int val_mask = 0x000fffff;
        vector<int> dp(N, 100001);
        dp[N - 1] = 0;
        for (int j = N - 2; j >= 0; j--) {
            if (A[j] == -1)
                continue;
            for (int i = 1; i <= B && j + i < N; i++) {
                if (A[j + i] == -1)
                    continue;
                if ((dp[j + i] & val_mask) + A[j + i] < (dp[j] & val_mask))
                    dp[j] = (((dp[j + i] & val_mask) + A[j + i]) | ((j + i) << 20));
            }
        }
        int idx = 0;
        vector<int> res = {};
        while (dp[idx] != 100001) {
            res.push_back(idx + 1);
            if (idx == N - 1)
                break;
            idx = (dp[idx] >> 20);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        int N = A.size();
        if (N == 0)
            return {};
        vector<int> dp(N, 100001), path(N, -1);
        dp[N - 1] = 0;
        for (int j = N - 2; j >= 0; j--) {
            if (A[j] == -1)
                continue;
            for (int i = 1; i <= B && j + i < N; i++) {
                if (A[j + i] == -1)
                    continue;
                if (dp[j + i] + A[j + i] < dp[j]) {
                    dp[j] = dp[j + i] + A[j + i];
                    path[j] = j + i;
                }
            }
        }
        int idx = 0;
        vector<int> res = {};
        while (dp[idx] != 100001) {
            res.push_back(idx + 1);
            if (idx == N - 1)
                break;
            idx = path[idx];
        }
        return res;
    }
};
