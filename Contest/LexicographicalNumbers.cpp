/*
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        if (n <= 9) {
            for (int i = 1; i <= n; i++)
                res.push_back(i);
        } else {
            for (int i = 1; i <= 9; i++) {
                res.push_back(i);
                lexicalOrderHelper(res, i, n);
            }
        }
        return res;
    }
    
    void lexicalOrderHelper(vector<int> &res, int s, int n) {
        int next = s*10;
        if (next <= n) {
            for (int i = 0; i <= min(9, n - next); i++) {
                int num = next + i;
                res.push_back(num);
                lexicalOrderHelper(res, num, n);
            }
        }
    }
};
