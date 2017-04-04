/*
Given an array with n integers, you need to find if there are triplets (i, j, k) which satisfies following conditions:
1. 0 < i, i + 1 < j, j + 1 < k < n - 1
2. Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal.
where we define that subarray (L, R) represents a slice of the original array starting from the element indexed L to the element indexed R.

Example:
Input: [1,2,1,2,1,2,1]
Output: True
Explanation:
i = 1, j = 3, k = 5. 
sum(0, i - 1) = sum(0, 0) = 1
sum(i + 1, j - 1) = sum(2, 2) = 1
sum(j + 1, k - 1) = sum(4, 4) = 1
sum(k + 1, n - 1) = sum(6, 6) = 1

Note:
1. 1 <= n <= 2000.
2. Elements in the given array will be in range [-1,000,000, 1,000,000].

Hide Tags Array
*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int N = nums.size();
        if (N < 7)
            return false;
        vector<int> sum(N, 0);
        sum[0] = nums[0];
        for (int i = 1; i < N; i++)
            sum[i] = sum[i - 1] + nums[i];

        for (int j = 3; j < N - 3; j++) {
            set<int> st;
            for (int i = 1; i < j - 1; i++) {
                if (sum[i - 1] == sum[j - 1] - sum[i])
                    st.insert(sum[i - 1]);
            }
            for (int k = j + 2; k < N - 1; k++) {
                if ((sum[N - 1] - sum[k] == sum[k - 1] - sum[j]) &&
                    (st.find(sum[k - 1] - sum[j]) != st.end()))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> data = {1,2,1,3,1,4,1};
    data = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    Solution sol;
    cout<<sol.splitArray(data);
	return 0;
}
