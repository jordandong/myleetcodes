/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2

Output: [0, 2]

Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

Output: [-34, -14, -10, -10, 10]

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int N = input.size();
        if (N == 0)
            return {};
        vector <int> res;
        for (int k = 0; k < N; k++) {
            if (is_op(input[k])) {
                vector<int> left = diffWaysToCompute(input.substr(0, k));
                vector<int> right = diffWaysToCompute(input.substr(k + 1));
                for (int i = 0; i < left.size(); i++) {
                    for (int j = 0; j < right.size(); j++) {
                        if (input[k] == '+')
                            res.push_back(left[i] + right[j]);
                        else if (input[k] == '-')
                            res.push_back(left[i] - right[j]);
                        else if (input[k] == '*')
                            res.push_back(left[i] * right[j]);
                    }
                }
            }
        }
        if (res.empty())
            res.push_back(atoi(input.c_str()));
        return res;
    }
    
    bool is_op(char &c) {
        return (c == '+' || c == '-' || c == '*');
    }
};
