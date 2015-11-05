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

//BFS, 212 ms
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_map<string, bool> visited;
        queue<string> q[2];
        int idx = 0;
        q[idx].push(s); //start from the longest string
        bool found = false;
        
        while (q[idx].size()) {
            string cur = q[idx].front();
            q[idx].pop();
            if (is_valid(cur)) {
                res.push_back(cur);
                found = true;
            }
            if (found) //continue to find in current level
                continue;

            for (int i = 0; i < cur.length(); i++) { //find all the possible next level strings by deleting one '(' or ')'
                if (cur[i] == '(' || cur[i] == ')') {
                    string next = cur.substr(0, i) + cur.substr(i + 1);
                    if (!visited[next]) {
                        q[idx ^ 1].push(next);
                        visited[next] = true;
                    }
                }
            }
            if (q[idx].empty()) //go to next level
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

//DFS, 22 ms
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> result; //avoid duplication
        int left_removed = 0;
        int right_removed = 0;
        for(auto &c : s) { //found how many '(' or ')' needs to be removed
            if(c == '(')
                ++left_removed;
            if(c == ')') {
                if(left_removed != 0)
                    --left_removed;
                else
                    ++right_removed;
            }
        }
        helper(s, 0, left_removed, right_removed, 0, "", result);
        return vector<string>(result.begin(), result.end());
    }

private:
    void helper(string s, int index, int left_removed, int right_removed, int pair, string path, unordered_set<string>& result) {
        if(index == s.size()) { //found solution
            if(left_removed == 0 && right_removed == 0 && pair == 0)
                result.insert(path);
            return;
        }
        
        if(s[index] != '(' && s[index] != ')') {
            helper(s, index + 1, left_removed, right_removed, pair, path + s[index], result);
        } else {
            if(s[index] == '(') {
                if(left_removed > 0)
                    helper(s, index + 1, left_removed - 1, right_removed, pair, path, result); //remove '('
                helper(s, index + 1, left_removed, right_removed, pair + 1, path + s[index], result); //use '('
            }

            if(s[index] == ')') {
                if(right_removed > 0)
                    helper(s, index + 1, left_removed, right_removed - 1, pair, path, result); //remove ')'
                if(pair > 0)
                    helper(s, index + 1, left_removed, right_removed, pair - 1, path + s[index], result); //use ')'
            }
        }
    }
};
