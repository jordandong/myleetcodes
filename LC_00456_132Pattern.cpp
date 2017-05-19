/*
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj.
Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

Note: n will be less than 15,000.

Example 1:
Input: [1, 2, 3, 4]
Output: False
Explanation: There is no 132 pattern in the sequence.

Example 2:
Input: [3, 1, 4, 2]
Output: True
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

Example 3:
Input: [-1, 3, 2, 0]
Output: True
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].

Hide Tags Stack
*/

//T : O(N), S : O(N)
class Solution {
public:
    /**
     * @param nums a list of n integers
     * @return true if there is a 132 pattern or false
     */
    bool find132pattern(vector<int>& nums) {
        // Write your code here
        stack<int> aj;
        int ak = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < ak)
                return true;
            
            while (!aj.empty() && aj.top() < nums[i]) {
                ak = aj.top();
                aj.pop();
            }
            aj.push(nums[i]);
        }
        return false;
    }
};

//T : O(N ^ 2), S : O(1)
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int N = nums.size();
        if (N < 3)
            return false;
        int mi = nums[0];
        for (int j = 1; j < N; j++) {
            mi = min(nums[j], mi);
            if (mi == nums[j])
                continue;
            for (int k = j + 1; k < N; k++) {
                if (mi < nums[k] && nums[k] < nums[j])
                    return true;
            }
        }
        return false;
    }
};

//T : O(N), S : O(N)
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int N = nums.size();
        if (N < 3)
            return false;
        vector<int> mi = nums;
        for (int i = 1; i < N; i++)
            mi[i] = min(nums[i - 1], mi[i - 1]);
            
        for (int k = N - 1, j = N; k > 0; k--) {
            if (nums[k] <= mi[k]) //ak < ai, pass
                continue;
            while (j < N && mi[j] <= mi[k]) //find current smallest one which are bigger than ai on the right part
                j++;
            if (j < N && nums[k] > mi[j]) //found
                return true;
            if (nums[k] > mi[k - 1]) //use the right side of mi array as a stack to store the values bigger than mi[k - 1]
                mi[--j] = nums[k];
        }
        return false;
    }
};
