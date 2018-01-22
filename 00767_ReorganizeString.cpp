/*
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].
*/

class Solution {
public:
    string reorganizeString(string S) {
        map<int, int> cnts;
        for (char c : S)
            cnts[c]++;
        priority_queue<pair<int, int>> pq;
        for (auto p : cnts) {
            if (p.second > (S.length() + 1) / 2)
                return "";
            pq.push({p.second, p.first});
        }

        string res;
        pair<int, int> top1, top2;
        while (!pq.empty()) {
            top1 = pq.top();
            pq.pop();
            res += top1.second;
            if (!pq.empty()) {
                res += pq.top().second;
                top2 = pq.top();
                pq.pop();
                if (top2.first > 1)
                    pq.push({ top2.first - 1, top2.second });
            }
            if (top1.first > 1)
                pq.push({ top1.first - 1, top1.second });
        }
        return res;        
    }
};
