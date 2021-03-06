/*
Given m arrays, and each array is sorted in ascending order.
Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance.
We define the distance between two integers a and b to be their absolute difference |a-b|.
Your task is to find the maximum distance.

Example 1:
Input: 
[[1,2,3],
 [4,5],
 [1,2,3]]
Output: 4
Explanation: 
One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.

Note:
1. Each given array will have at least 1 number. There will be at least two non-empty arrays.
2. The total number of the integers in all the m arrays will be in the range of [2, 10000].
3. The integers in the m arrays will be in the range of [-10000, 10000].
*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int N = arrays.size();
        if (N < 2)
            return -1;
        int mi = arrays[0][0], mx = arrays[0].back(), res = 0;
        for (int i = 1; i < N; i++) {
            res = max(mx - arrays[i][0], res);
            res = max(arrays[i].back() - mi, res);
            mi = min(mi, arrays[i][0]);
            mx = max(mx, arrays[i].back());
        }
        return res;
    }
};
