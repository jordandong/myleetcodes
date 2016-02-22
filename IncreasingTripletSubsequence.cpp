/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.
Given [5, 4, 3, 2, 1],
return false.

Credits:
Special thanks to @DjangoUnchained for adding this problem and creating all test cases.
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int s = INT_MAX, b = INT_MAX;
        for (int &e : nums) {
            if (e <= s) {
                s = e;
            } else if (e <= b) {
                b = e; 
            } else {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        stack<int> stk;
        int i = 0;
        for  (auto &e : nums) {
            if (stk.size() == 1 && stk.top() >= e) {
                stk.pop();
                stk.push(e);
            } else if (stk.size() == 2 && stk.top() > e) {
                int b = stk.top();
                stk.pop();
                int s = stk.top();
                stk.pop();
                if (s < e && e < b) {
                    stk.push(s);
                    stk.push(e);
                } else if (e <= s){
                    stk.push(e);
                    stk.push(b);
                }
            } else if (stk.empty() || stk.top() < e){
                stk.push(e);
            }
            if (stk.size() == 3)
                return true;
        }
        return false;
    }
};
