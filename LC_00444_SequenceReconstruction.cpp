/*
Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it).
Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

Example 1:
Input:
org: [1,2,3], seqs: [[1,2],[1,3]]
Output:
false
Explanation:
[1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.

Example 2:
Input:
org: [1,2,3], seqs: [[1,2]]
Output:
false
Explanation:
The reconstructed sequence can only be [1,2].

Example 3:
Input:
org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]
Output:
true
Explanation:
The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].

Example 4:
Input:
org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]
Output:
true
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
A. Every sequence in seqs should be a subsequence in org. This part is obvious.
B. Every 2 consecutive elements in org should be consecutive elements in some sequence from seqs. For 2 any consecutive elements x and y in org we have 2 options.
B1. We have both xand y in some sequence from seqs. Then (as condition 1 is satisfied) they must be consequtive elements in this sequence.
B2. There is no sequence in seqs that contains both x and y. In this case we cannot uniquely reconstruct org from seqs as sequence with x and y switched would also be a valid original sequence for seqs.
*/

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, int> m, pre;
        for (int i = 0; i < org.size(); i++) 
            m[org[i]] = i;
        for (const auto& v: seqs) {
            for (int i = 0; i < v.size(); i++) {
                if (m.find(v[i]) == m.end())
                    return false;
                if (i > 0 && m[v[i - 1]] >= m[v[i]])
                    return false;
                if (pre.find(v[i]) == pre.end())
                    pre[v[i]] = i > 0 ? m[v[i - 1]] : -1;
                else 
                    pre[v[i]] = max(pre[v[i]], i > 0 ? m[v[i - 1]] : -1);
            }   
        }

        for (int i = 0; i < org.size(); i++) {
            if (pre[org[i]] != i - 1)
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> org;
    vector<vector<int>> seqs;
    org = {1,2,3};
    seqs = {{1,2},{1,3}};
    cout<<s.sequenceReconstruction(org, seqs)<<endl;
    org = {1,2,3};
    seqs = {{1,2}};
    cout<<s.sequenceReconstruction(org, seqs)<<endl;
    org = {1,2,3};
    seqs = {{1,2},{1,3},{2,3}};
    cout<<s.sequenceReconstruction(org, seqs)<<endl;
    org = {4,1,5,2,6,3};
    seqs = {{5,2,6,3},{4,1,5,2}};
    cout<<s.sequenceReconstruction(org, seqs)<<endl;
    return 0;
}

0
0
1
1
