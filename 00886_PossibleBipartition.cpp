/*
We want to split a group of n people (labeled from 1 to n) into two groups of any size.
Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 
Example 1:
Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].

Example 2:
Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

Example 3:
Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 
Constraints:
1 <= n <= 2000
0 <= dislikes.length <= 104
dislikes[i].length == 2
1 <= dislikes[i][j] <= n
ai < bi
All the pairs of dislikes are unique.
*/

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> edges(n + 1);
        for (auto e : dislikes) {
            edges[e[0]].push_back(e[1]);
            edges[e[1]].push_back(e[0]);
        }
        
        vector<int> parents(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            int parent_i = Find(parents, i);
            int parent_j0;
            for (int j = 0; j < edges[i].size(); j++) {
                int parent_j = Find(parents, edges[i][j]);
                if (parent_i == parent_j) {
                    return false;
                }
                if (j == 0) {
                    parent_j0 = parent_j;
                }
                parents[parent_j] = parent_j0;
                //if (j != 0) {
                //    Union(parents, edges[i][0], edges[i][j]);
                //}
            }
        }
        return true;
    }
    
    int Find(vector<int> &parents, int c) {
        if (parents[c] == -1) {
            return c;
        }
        if (parents[c] != c) {
            return Find(parents, parents[c]);
        }
        return c;
    }
    
    void Union(vector<int> &parents, int p, int c) {
        int p1 = Find(parents, p);
        int p2 = Find(parents, c);
        parents[p2] = p1; 
    }
};
