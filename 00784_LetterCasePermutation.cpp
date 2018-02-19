/*
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:
S will be a string with length at most 12.
S will consist only of letters or digits.
*/

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        letterCasePermutationHelper(S, 0, ans);
        return ans;
    }
private:
    void letterCasePermutationHelper(string S, int idx, vector<string> &ans) {
        if (idx == S.length()) {
            ans.push_back(S);
            return;
        }
        
        letterCasePermutationHelper(S, idx + 1, ans);
        if ('a' <= S[idx] && S[idx] <= 'z') {
            S[idx] = 'A' + (S[idx] - 'a');
            letterCasePermutationHelper(S, idx + 1, ans);
        } else if ('A' <= S[idx] && S[idx] <= 'Z') {
            S[idx] = 'a' + (S[idx] - 'A');
            letterCasePermutationHelper(S, idx + 1, ans);
        }
    }
};
