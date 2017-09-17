/*
You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.

Example 1:
Input: [4, 1, 8, 7]
Output: True
Explanation: (8-4) * (7-1) = 24
Example 2:
Input: [1, 2, 1, 2]
Output: False
Note:
The division operator / represents real division, not integer division. For example, 4 / (1 - 2/3) = 12.
Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.
*/

class Solution {
private:
    double eps;
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> A;
        eps = 0.0001;
        for (auto e : nums)
            A.push_back((double)e);
        return judgePoint24Helper(A);
    }
    
    bool judgePoint24Helper(vector<double> A) {
        int N = A.size();
        if (N == 1)
            return abs(A[0] - 24.0) < eps;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                vector<double> next;
                for (int k = 0; k < N; k++) {
                    if (k != i && k != j)
                        next.push_back(A[k]);
                }
                
                next.push_back(A[i] + A[j]);
                if (judgePoint24Helper(next))
                    return true;
                
                next[next.size() - 1] = (A[i] * A[j]);
                if (judgePoint24Helper(next))
                    return true;
                
                next[next.size() - 1] = (A[i] - A[j]);
                if (judgePoint24Helper(next))
                    return true;
                
                next[next.size() - 1] = (A[j] - A[i]);
                if (judgePoint24Helper(next))
                    return true;
                
                if (abs(A[j]) > eps) {
                    next[next.size() - 1] = (A[i] / A[j]);
                    if (judgePoint24Helper(next))
                        return true;
                }
                
                if (abs(A[i]) > eps) {
                    next[next.size() - 1] = (A[j] / A[i]);
                    if (judgePoint24Helper(next))
                        return true;
                }
            }
        }
        return false;
    }
};
