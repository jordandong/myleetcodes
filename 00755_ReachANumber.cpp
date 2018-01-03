/*
You are standing at position 0 on an infinite number line. There is a goal at position target.

On each move, you can either go left or right. During the n-th move (starting from 1), you take n steps.

Return the minimum number of steps required to reach the destination.

Example 1:
Input: target = 3
Output: 2
Explanation:
On the first move we step from 0 to 1.
On the second step we step from 1 to 3.
Example 2:
Input: target = 2
Output: 3
Explanation:
On the first move we step from 0 to 1.
On the second move we step  from 1 to -1.
On the third move we step from -1 to 2.
Note:
target will be a non-zero integer in the range [-10^9, 10^9].
*/

/*
[1, -1]
[1, 3, -3, -1]
[0, 2, 4, 6, -6, -4, -2]
[0, 2, 4, 6, 8, 10, -10, -8, -6, -4, -2]
[1, 3, 5, 7, 9, 11, 13, 15, -15, -13, -11, -9, -7, -5, -3, -1]
[1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, -21, -19, -17, -15, -13, -11, -9, -7, -5, -3, -1]
setp N to reach max S(N) = N*(N + 1)/2
*/

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int ans = 0, sum = 0;
        //find the first sum at setp ans >= target, odd and even are the same
        while (sum % 2 != target % 2 || sum < target) {
            ans++;
            sum += ans;
        }
        return ans;
    }
};
