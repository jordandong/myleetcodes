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


//DP to avoid duplicated computation
class Solution {
public:

    vector<int> diffWaysToCompute(string input) {
        int N = input.size();
        if (N == 0)
            return {};
        vector<int> sol = {};
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, sol));
        return diffWaysToComputeHelper(input, 0, N - 1, dp);
    }
    
    vector<int> diffWaysToComputeHelper(string &input, int start, int end, vector<vector<vector<int>>> &dp) {
        vector <int> res;
        for (int k = start; k <= end; k++) {
            if (is_op(input[k])) {
                vector<int> left = dp[start][k - 1];
                vector<int> right = dp[k + 1][end];
                if (left.size() == 0)
                    left = diffWaysToComputeHelper(input, start, k - 1, dp);
                if (right.size() == 0)
                    right = diffWaysToComputeHelper(input, k + 1, end, dp);
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
            res.push_back(atoi(input.substr(start, end - start + 1).c_str()));
        dp[start][end] = res;
        return res;
    }
    
    bool is_op(char &c) {
        return (c == '+' || c == '-' || c == '*');
    }
};

//Non DP, using reference instead of copying value
class Solution {
public:

    vector<int> diffWaysToCompute(string input) {
        int N = input.size();
        if (N == 0)
            return {};
        return diffWaysToComputeHelper(input, 0, N - 1);
    }
    
    vector<int> diffWaysToComputeHelper(string &input, int start, int end) {
        vector <int> res;
        for (int k = start; k <= end; k++) {
            if (is_op(input[k])) {
                vector<int> left = diffWaysToComputeHelper(input, start, k - 1);
                vector<int> right = diffWaysToComputeHelper(input, k + 1, end);
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
            res.push_back(atoi(input.substr(start, end - start + 1).c_str()));
        return res;
    }
    
    bool is_op(char &c) {
        return (c == '+' || c == '-' || c == '*');
    }
};

//Non-DP, duplicated computation + pass value
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
