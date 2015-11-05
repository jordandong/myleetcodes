/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses '( and ')'.

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]

Credits:
Special thanks to @hpplayer for adding this problem and creating all test cases.

Hide Tags Depth-first Search Breadth-first Search
*/

//BFS
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_map<string, bool> visited;
        queue<string> q[2];
        int idx = 0;
        q[idx].push(s);
        bool found = false;
        
        while (q[idx].size()) {
            string cur = q[idx].front();
            q[idx].pop();
            if (is_valid(cur)) {
                res.push_back(cur);
                found = true;
            }
            if (found)
                continue;

            for (int i = 0; i < cur.length(); i++) {
                if (cur[i] == '(' || cur[i] == ')') {
                    string next = cur.substr(0, i) + cur.substr(i + 1);
                    if (!visited[next]) {
                        q[idx ^ 1].push(next);
                        visited[next] = true;
                    }
                }
            }
            if (q[idx].empty())
                idx ^= 1;
        }
        return res;
    }
    
    bool is_valid(string &s) {
        int cnt = 0;
        for (auto &c : s) {
            if (c == '(') {
                cnt++;
            } else if (c == ')') {
                cnt--;
            }
            if (cnt < 0)
                return false;
        }
        return cnt == 0;
    }
};
